""" IntCode Computer Module"""

def get_instruction(opcode):
    """ Returns the two first digits """
    return opcode % 100

def get_mode(opcode):
    """ Returns the modes for parameters """
    mode_list = [int((opcode % 1000) / 100),
                 int((opcode % 10000) / 1000),
                 int((opcode % 100000) / 10000)]
    return mode_list
class Ic:
    """ IntCode Computer Class"""

    def __init__(self, file_name, phase, verbose=False):
        """ Constructor """
        input_file = open(file_name)
        file_content = input_file.read()
        self.phase = phase
        self.input_values = [phase]
        self.data = file_content.split(',')
        self.data = [int(value) for value in self.data]
        self.p_c = 0     # Program counter
        self.program_length = len(self.data)
        self.printed_value = None
        self.verbose = verbose
        self.done = False

    def __tick_computer(self, steps):
        """ Tick the computer by moving program counter given steps ahead """
        if (self.p_c + steps) == self.program_length:
            raise Exception("End of program reached")
        else:
            self.p_c += steps

    def __set_program_pointer(self, position):
        self.p_c = position

    def reset(self):
        """ Resets the computer """
        self.p_c = 0
        self.input_values = [self.phase]
        self.done = False

    def is_done(self):
        """ Returns weather the computer is done or not """
        return self.done

    def get_result(self):
        """ Returns the last printed value by the computer. None if nothing printed yet """
        return self.printed_value

    def get_operation(self):
        """ Returns operation at current program pointer """
        instruction = self.data[self.p_c]
        #self.tick_computer(1)
        return instruction

    def get_value(self, position, mode=0):
        """ Get value at given position """
        if mode == 0:
            return int(self.data[position])
        else:
            return position

    def add_input(self, input_value):
        """ Add input value for the computer """
        self.input_values.append(input_value)

    def write_value(self, position, value):
        """ Write value in memory """
        self.data[position] = value

    def start_computer(self):
        """ Start the computer at given position """

        if self.verbose:
            print("Computer started at: {}".format(self.p_c))
        while True:
            opcode = self.get_operation()
            instruction = get_instruction(opcode)
            modes = get_mode(opcode)
            # print("PC: {}, instruction: {}".format(self.p_c, instruction))
            # print("..{}".format(self.data)) # for debugging

            if instruction == 99: # Terminate program
                if self.verbose:
                    print("OP-Code 99 found, terminating")
                # print(self.data) # for debugging
                self.done = True
                if self.verbose:
                    print("Computer done")
                break

            elif instruction == 1: # Add
                read_pos_1 = self.get_value(self.p_c + 1)
                read_pos_2 = self.get_value(self.p_c + 2)
                write_pos = self.get_value(self.p_c + 3)

                value_1 = self.get_value(read_pos_1, modes[0])
                value_2 = self.get_value(read_pos_2, modes[1])
                result_value = value_1 + value_2

                self.write_value(write_pos, result_value)
                self.__tick_computer(4)

            elif instruction == 2: # multiply
                read_pos_1 = self.get_value(self.p_c + 1)
                read_pos_2 = self.get_value(self.p_c + 2)
                write_pos = self.get_value(self.p_c + 3)

                value_1 = self.get_value(read_pos_1, modes[0])
                value_2 = self.get_value(read_pos_2, modes[1])

                result_value = value_1 * value_2

                self.write_value(write_pos, result_value)
                self.__tick_computer(4)

            elif instruction == 3: # Read from input
                # print("input parameter: ", end='')
                # input_value = input()
                if len(self.input_values) == 0:
                    if self.verbose:
                        print("Need input value")
                    break
                else:
                    input_value = self.input_values.pop(0)
                    if self.verbose:
                        print("input: {}".format(input_value))
                    write_pos = self.get_value(self.p_c + 1)
                    self.write_value(write_pos, input_value)
                    # print("{}, {}".format(write_pos, self.get_value(write_pos))) # for debugging
                    self.__tick_computer(2)

            elif instruction == 4: # Print value at position
                read_pos = self.get_value(self.p_c + 1, modes[0])
                read_value = self.get_value(read_pos)
                self.printed_value = read_value
                print("Print instruction, pos: {}, value: {}".format(read_pos, read_value))
                self.__tick_computer(2)

            elif instruction == 5: # jump if true
                read_pos = self.get_value(self.p_c + 1)
                read_pc_pos = self.get_value(self.p_c + 2)

                eval_value = self.get_value(read_pos, modes[0])
                new_pc_pos = self.get_value(read_pc_pos, modes[1])

                if eval_value != 0:
                    self.__set_program_pointer(new_pc_pos)
                else:
                    self.__tick_computer(3)

            elif instruction == 6: # jump if false
                read_pos = self.get_value(self.p_c + 1)
                read_pc_pos = self.get_value(self.p_c + 2)

                eval_value = self.get_value(read_pos, modes[0])
                new_pc_pos = self.get_value(read_pc_pos, modes[1])

                if eval_value == 0:
                    self.__set_program_pointer(new_pc_pos)
                else:
                    self.__tick_computer(3)

            elif instruction == 7: # less than
                param_1_pos = self.get_value(self.p_c + 1)
                param_2_pos = self.get_value(self.p_c + 2)
                write_pos = self.get_value(self.p_c + 3)

                value_1 = self.get_value(param_1_pos, modes[0])
                value_2 = self.get_value(param_2_pos, modes[1])

                if value_1 < value_2:
                    self.write_value(write_pos, 1)
                else:
                    self.write_value(write_pos, 0)

                self.__tick_computer(4)

            elif instruction == 8: # equals
                param_1_pos = self.get_value(self.p_c + 1)
                param_2_pos = self.get_value(self.p_c + 2)
                write_pos = self.get_value(self.p_c + 3)

                value_1 = self.get_value(param_1_pos, modes[0])
                value_2 = self.get_value(param_2_pos, modes[1])

                if value_1 == value_2:
                    self.write_value(write_pos, 1)
                else:
                    self.write_value(write_pos, 0)

                self.__tick_computer(4)
            else:
                raise Exception("Invalid op-code: {}".format(instruction))
