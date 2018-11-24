#include <application.h>

    int exit_gate;
    int entry_gate;
    int exit_state = 0;
    int entry_state = 0;

void application_task()
{
    exit_gate = bc_gpio_get_input(BC_GPIO_P8);
    entry_gate = bc_gpio_get_input(BC_GPIO_P9);

    if (entry_gate == 0 && entry_state == 0){
        bc_log_info("Entry");
        bc_radio_pub_string("zavory/", "Entry");
        entry_state = 1;
        }
        else if (entry_gate == 1 && entry_state == 1){
        entry_state = 0;

        
    }

    if (exit_gate == 0 && exit_state == 0){
        bc_log_info("Exit");
        bc_radio_pub_string("zavory/", "Exit");
        exit_state = 1;
        }
        else if (exit_gate == 1 && exit_state == 1){
        exit_state = 0;
    }
    bc_scheduler_plan_current_relative(100);
}

void application_init(void)
{
    bc_log_init(BC_LOG_LEVEL_INFO, BC_LOG_TIMESTAMP_ABS);
    bc_gpio_init(BC_GPIO_P8);
    bc_gpio_init(BC_GPIO_P9);
    bc_gpio_set_mode(BC_GPIO_P8, BC_GPIO_MODE_INPUT);
    bc_gpio_set_mode(BC_GPIO_P9, BC_GPIO_MODE_INPUT);
    bc_gpio_set_pull(BC_GPIO_P8, BC_GPIO_PULL_UP);
    bc_gpio_set_pull(BC_GPIO_P9, BC_GPIO_PULL_UP);
}



