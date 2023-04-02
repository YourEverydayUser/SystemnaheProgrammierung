/**
 * @file
 * @brief  Implementation
 */
#include "model.h"
#include <assert.h>

/**
 * @brief       Asserts that the position is in range.
 * @param [IN]  The position to check.
 */
static void assert_pos(model_pos_t pos)
{
    assert(pos.row < MODEL_SIZE);
    assert(pos.col < MODEL_SIZE);
}

/**
 * @brief                    Sets the field on the board to the given state.
 * @param  instance [INOUT]  The instance which holds the state.
 * @param  pos      [IN]     The affected field.
 * @param  state    [IN]     The new state of the field.
 */
static void set_state(model_t *instance, model_pos_t pos, model_state_t state)
{
    assert_pos(pos);
    // set the field of the board to the new state
    instance->board[pos.col][pos.row] = state;
}

model_pos_t model_pos(size_t row, size_t col)
{
    return (model_pos_t){row, col};
}

void model_init(model_t *instance)
{
    assert(instance);
    // set all fields of the board to model_state_none
    int i, j;

    for(i=0; i < MODEL_SIZE; i++) {
        for(j=0; j < MODEL_SIZE; j++) {  
            set_state(instance, model_pos(i, j), model_state_none);
        }
    }
}

model_state_t model_get_state(model_t *instance, model_pos_t pos)
{
    assert(instance);
    assert_pos(pos);
    // replace the stub implementation my access to the field at the given position.
    return instance->board[pos.row][pos.col];
}


model_line_t model_get_win_line(model_t *instance)
{
    assert(instance);
    model_state_t anchor;
    
    // horizontal
    for(size_t row = 0; row < MODEL_SIZE; row++) {
        anchor = model_get_state(instance, model_pos(row, 0));
        if (anchor != model_state_none
            && anchor == model_get_state(instance, model_pos(row, 1))
            && anchor == model_get_state(instance, model_pos(row, 2))) {
            return (model_line_t) { model_dir_h, { row, 0 } };
        }
    }
    
    // vertical
    for(size_t col = 0; col < MODEL_SIZE; col++) {
        anchor = model_get_state(instance, model_pos(0, col));
        if (anchor != model_state_none
            && anchor == model_get_state(instance, model_pos(1, col))
            && anchor == model_get_state(instance, model_pos(2, col))) {
            return (model_line_t) { model_dir_v, { 0, col } };
        }


    }
    
    // diagonal
    anchor = model_get_state(instance, model_pos(1, 1));
    if (anchor != model_state_none) {
        if (anchor == model_get_state(instance, model_pos(0, 0)) && anchor == model_get_state(instance, model_pos(2, 2))) {
            return (model_line_t) { model_dir_d, { 0, 0 } };
        }
        if (anchor == model_get_state(instance, model_pos(2, 0)) && anchor == model_get_state(instance, model_pos(0, 2))) {
            return (model_line_t) { model_dir_d, { 0, 2 } };
        }
    }

    // fallback
    return (model_line_t) { model_dir_none, { 0, 0 } }; 
}

model_state_t model_get_winner(model_t *instance)
{
    assert(instance);
    model_line_t line = model_get_win_line(instance);
    return line.dir == model_dir_none
        ? model_state_none
        : model_get_state(instance, model_pos(line.start.row, line.start.col))
        ;
}

int model_can_move(model_t *instance)
{
    assert(instance);
    if (model_get_winner(instance) == model_state_none) {
        // scan all fields: return 1 with first field which equals model_state_none
        int i, j;

        for(i=0; i < MODEL_SIZE; i++) {
            for(j=0; j < MODEL_SIZE; j++) {  
                if(model_get_state(instance, model_pos(i, j)) == model_state_none) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// public API function which is documented in the header file.
int model_move(model_t *instance, model_pos_t pos, model_state_t state)
{
    assert(instance);
    assert_pos(pos);
    if (model_get_state(instance, pos) == model_state_none && model_can_move(instance)) {
        set_state(instance, pos, state);
        return 1;
    }
    return 0;
}
