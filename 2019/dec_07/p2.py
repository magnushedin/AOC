""" Problem for dec_07 - 2019 """

import sys
import ic
import itertools

FILENAME = "./2019/dec_07/input_ex2"

if len(sys.argv) > 1:
    FILENAME = sys.argv[1]

# All permutations of the phase setting
phase_setting_permutations = list(itertools.permutations([5, 6, 7, 8, 9]))

#phase_setting_permutations = [(9, 8, 7, 6, 5)] # for debugging
amp_input = 0 # initial input for the first amplifier
max_output = 0

for phase_setting in phase_setting_permutations:
    amp_input = 0 # initial input for the first amplifier
    print("phase_setting: {}".format(phase_setting))

    amps = []

    for phase in phase_setting:
        amps.append(ic.Ic(FILENAME, phase, verbose=False))

    while not amps[0].is_done():
        for amp in amps:
            amp.add_input(amp_input)
            amp.start_computer()
            amp_input = amp.get_result()

    print("amp_5: {}".format(amp_input))

    if max_output < amp_input:
        max_output = amp_input

print("Highest output: {}".format(max_output))
