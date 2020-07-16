""" IntCode Computer Module"""

class Ic:
    """ IntCode Computer Class"""

    def __init__(self, file_name):
        input_file = open(file_name)
        file_content = input_file.read()
        self.data = file_content.split(',')
        self.data = [int(value) for value in self.data]
        self.p_c = 0     # Program counter
        self.program_length = len(self.data)

    def __tick_computer(self, steps):
        """ Tick the computer by moving program counter ahead """
        if (self.p_c + steps) == self.program_length:
            raise Exception("End of program reached")
        else:
            self.p_c += steps

    def get_operation(self):
        """ Returns next command """
        instruction = self.data[self.p_c]
        #self.tick_computer(1)
        return instruction

    def get_value(self, position):
        return int(self.data[position])

    def write_value(self, position, value):
        """ Write value in memory """
        self.data[position] = value

    def start_computer(self, p_c):
        """ Start the computer at given position """
        self.p_c = p_c

        print("Computer statrted at: {}".format(p_c))
        while True:
            instruction = self.get_operation()
            print("PC: {}".format(self.p_c))
            print("..{}".format(self.data))

            if instruction == 99:
                print("OP-Code 99 found, terminating")
                print(self.data)
                break
            elif instruction == 1:
                read_pos_1 = self.get_value(self.p_c + 1)
                read_pos_2 = self.get_value(self.p_c + 2)
                write_pos = self.get_value(self.p_c + 3)

                value_1 = self.get_value(read_pos_1)
                value_2 = self.get_value(read_pos_2)
                result_value = value_1 + value_2

                self.write_value(write_pos, result_value)
                self.__tick_computer(4)
            elif instruction == 2:
                read_pos_1 = self.get_value(self.p_c + 1)
                read_pos_2 = self.get_value(self.p_c + 2)
                write_pos = self.get_value(self.p_c + 3)

                value_1 = self.get_value(read_pos_1)
                value_2 = self.get_value(read_pos_2)
                result_value = value_1 * value_2

                self.write_value(write_pos, result_value)
                self.__tick_computer(4)
            else:
                raise Exception("Invalid op-code: {}".format(instruction))
