""" Problem for dec_07 - 2019 """

import sys
import ic
import itertools

FILENAME = "./2019/dec_07/input_ex1"

if len(sys.argv) > 1:
    FILENAME = sys.argv[1]

# All permutations of the phase setting
phase_setting_permutations = list(itertools.permutations([0, 1, 2, 3, 4]))

#phase_setting_permutations = [(4, 3, 2, 1, 0)] # for debugging
amp_input = 0 # initial input for the first amplifier
max_output = 0
max_phase = list()

for phase_setting in phase_setting_permutations:
    amp_input = 0 # initial input for the first amplifier
    print("phase_setting: {}".format(phase_setting))
    for phase in phase_setting:
        print("phase: {}".format(phase))
        my_ic = ic.Ic(FILENAME, amp_input, phase)
        my_ic.start_computer(0)
        amp_input = my_ic.get_result()
        if max_output < amp_input:
            max_output = amp_input
            max_phase = phase_setting


    print("{}: {}".format(max_output, max_phase))
