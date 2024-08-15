#include "matrix.h"

static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;


static void unselect_row(uint8_t row) {
    gpio_set_pin_input_high(row_pins[row]);
}

static void unselect_col(uint8_t col) {
    gpio_set_pin_input_high(col_pins[col]);
}

static void select_row(uint8_t row) {
    gpio_set_pin_output(row_pins[row]);
    gpio_write_pin_low(row_pins[row]);
}

static void select_col(uint8_t col) {
    gpio_set_pin_output(col_pins[col]);
    gpio_write_pin_low(col_pins[col]);
}

void matrix_init_custom(void) {
    for (int row = 0; row < MATRIX_ROWS; row++) {
        unselect_row(row);
    }
    for (int col = 0; col < MATRIX_COLS; col += 2) {
        unselect_col(col);
    }
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    matrix_row_t last_row_val = current_matrix[current_row];

    select_row(current_row);
    matrix_io_delay();

    for (uint8_t col = 0; col < MATRIX_COLS; col += 2) {
        if (gpio_read_pin(col_pins[col])) {
            current_matrix[current_row] &= ~(MATRIX_ROW_SHIFTER << col);
        } else {
            current_matrix[current_row] |= MATRIX_ROW_SHIFTER << col;
        }
    }

    unselect_row(current_row);
    return last_row_val != current_matrix[current_row];
}

static bool read_rows_on_cols(matrix_row_t current_matrix[], uint8_t current_col) {
    bool changed = false;

    select_col(current_col);
    matrix_io_delay();

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        matrix_row_t last_row_val = current_matrix[row];

        if (gpio_read_pin(row_pins[row])) {
            current_matrix[row] &= ~(MATRIX_ROW_SHIFTER << current_col);
        } else {
            current_matrix[row] |= MATRIX_ROW_SHIFTER << current_col;
        }

        changed |= last_row_val != current_matrix[row];
    }

    unselect_col(current_col);
    return changed;
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool matrix_has_changed = false;

    for (int row = 0; row < MATRIX_ROWS; row++) {
        matrix_has_changed |= read_cols_on_row(current_matrix, row);
    }
    for (int col = 1; col < MATRIX_COLS; col += 2) {
        matrix_has_changed |= read_rows_on_cols(current_matrix, col);
    }

    return matrix_has_changed;
}
