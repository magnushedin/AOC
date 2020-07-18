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

    def __init__(self, file_name, system_id):
        """ Constructor """
        input_file = open(file_name)
        file_content = input_file.read()
        self.system_id = system_id
        self.data = file_content.split(',')
        self.data = [int(value) for value in self.data]
        self.p_c = 0     # Program counter
        self.program_length = len(self.data)

    def __tick_computer(self, steps):
        """ Tick the computer by moving program counter given steps ahead """
        if (self.p_c + steps) == self.program_length:
            raise Exception("End of program reached")
        else:
            self.p_c += steps

    def __set_program_pointer(self, position):
        self.p_c = position

    def get_operation(self):
        """ Returns operation at current program pointer """
        instruction = self.data[self.p_c]
        #self.tick_computer(1)
        return instruction

    def get_value(self, position):
        """ Get value at given position """
        return int(self.data[position])

    def write_value(self, position, value):
        """ Write value in memory """
        self.data[position] = value

    def start_computer(self, p_c):
        """ Start the computer at given position """
        self.p_c = p_c

        print("Computer started at: {}".format(p_c))
        while True:
            opcode = self.get_operation()
            instruction = get_instruction(opcode)
            modes = get_mode(opcode)
            # print("PC: {}, instruction: {}".format(self.p_c, instruction))
            # print("..{}".format(self.data)) # for debugging

            if instruction == 99: # Terminate program
                print("OP-Code 99 found, terminating")
                # print(self.data) # for debugging
                break

            elif instruction == 1: # Add
                read_pos_1 = self.get_value(self.p_c + 1)
                read_pos_2 = self.get_value(self.p_c + 2)
                write_pos = self.get_value(self.p_c + 3)

                if modes[0] == 0:
                    value_1 = self.get_value(read_pos_1)
                else:
                    value_1 = read_pos_1

                if modes[1] == 0:
                    value_2 = self.get_value(read_pos_2)
                else:
                    value_2 = read_pos_2
                result_value = value_1 + value_2

                self.write_value(write_pos, result_value)
                self.__tick_computer(4)

            elif instruction == 2: # multiply
                read_pos_1 = self.get_value(self.p_c + 1)
                read_pos_2 = self.get_value(self.p_c + 2)
                write_pos = self.get_value(self.p_c + 3)

                if modes[0] == 0:
                    value_1 = self.get_value(read_pos_1)
                else:
                    value_1 = read_pos_1

                if modes[1] == 0:
                    value_2 = self.get_value(read_pos_2)
                else:
                    value_2 = read_pos_2
                result_value = value_1 * value_2

                self.write_value(write_pos, result_value)
                self.__tick_computer(4)

            elif instruction == 3: # Read from input
                print("input parameter: ", end='')
                input_value = self.system_id
                write_pos = self.get_value(self.p_c + 1)
                self.write_value(write_pos, input_value)
                # print("{}, {}".format(write_pos, self.get_value(write_pos))) # for debugging
                self.__tick_computer(2)

            elif instruction == 4: # Print value at position
                read_pos = self.get_value(self.p_c + 1)
                read_value = self.get_value(read_pos)
                print("Print instruction, pos: {}, value: {}".format(read_pos, read_value))
                self.__tick_computer(2)

            elif instruction == 5: # jump if true
                read_pos = self.get_value(self.p_c + 1)
                read_pc_pos = self.get_value(self.p_c + 2)

                if modes[0] == 0:
                    eval_value = self.get_value(read_pos)
                else:
                    eval_value = read_pos

                if modes[1] == 0:
                    new_pc_pos = self.get_value(read_pc_pos)
                else:
                    new_pc_pos = read_pc_pos

                if eval_value != 0:
                    self.__set_program_pointer(new_pc_pos)
                else:
                    self.__tick_computer(3)

            elif instruction == 6: # jump if false
                read_pos = self.get_value(self.p_c + 1)
                read_pc_pos = self.get_value(self.p_c + 2)

                if modes[0] == 0:
                    eval_value = self.get_value(read_pos)
                else:
                    eval_value = read_pos

                if modes[1] == 0:
                    new_pc_pos = self.get_value(read_pc_pos)
                else:
                    new_pc_pos = read_pc_pos

                if eval_value == 0:
                    self.__set_program_pointer(new_pc_pos)
                else:
                    self.__tick_computer(3)

            elif instruction == 7: # less than
                pass
            elif instruction == 8: # equals
                pass
            else:
                raise Exception("Invalid op-code: {}".format(instruction))
