def prepare(token):
  if token == "moo":
    return 0
  elif token == "mOo":
    return 1
  elif token == "moO":
    return 2
  elif token == "mOO":
    return 3
  elif token == "Moo":
    return 4
  elif token == "MOo":
    return 5
  elif token == "MoO":
    return 6
  elif token == "MOO":
    return 7
  elif token == "OOO":
    return 8
  elif token == "MMM":
    return 9
  elif token == "OOM":
    return 10
  elif token == "oom":
    return 11

def exec(comand, pointer):
    global data
    global data_pointer
    global start_loop_pointer
    global register

    if comand == 7:
        #print("start loop")
        start_loop_pointer.append(pointer)
    elif comand == 1:
        #print("move data_pointer back")
        data_pointer -= 1
    elif comand == 2:
        #print("move data_pointer forward")
        data_pointer += 1

    elif comand == 3:
        #print("Execute command")
        if (data[data_pointer] == 3):
          raise Exception('invalid exec')
        exec(data[data_pointer],pointer)

    elif comand == 4:
        #print("read/write data")
        if (data[data_pointer] == 0):
          data[data_pointer] = ord(input())
        else:
          print(chr(data[data_pointer]), end='')

    elif comand == 5:
        #print("decrease data value")
        while len(data) <= data_pointer:
          data.append(0)
        data[data_pointer] -= 1

    elif comand == 6:
        #print("increase data value")
        while len(data) <= data_pointer:
          data.append(0)
        data[data_pointer] += 1

    elif comand == 0:
        #print("end loop command. dest: ",end="")
        if len(start_loop_pointer) == 0:
          raise Exception('error! start loop not found')
        while len(data) <= data_pointer:
          data.append(0)
        if (data[data_pointer] == 0):
          pointer = start_loop_pointer[len(start_loop_pointer)-1]
          #print(pointer, end='')
        else:
          start_loop_pointer.pop()
        #print()
    elif comand == 8:
        #print("reset data block")
        while len(data) <= data_pointer:
          data.append(0)
        data[data_pointer] = 0

    elif comand == 9:
        #print("Copy to register/paste from register")
        if register is None:
            register = data[data_pointer]
        else:
            while len(data) <= data_pointer:
              data.append(0)
            data[data_pointer] = register
            register = None

    elif comand == 10:
        print(data[data_pointer], end= '')

    elif comand == 11:
        while len(data) <= data_pointer:
          data.append(0)
        data[data_pointer] = int(input())

    else:
        raise Exception('Compile error!')
    return pointer + 1








instructions_data = open("hello.cow", "r").readlines()
instruct = []
for i in instructions_data:
   for j in i.split():
     if j.lower() == "moo" or j.lower() == "mmm" or j.lower() == "oom":
       instruct.append(prepare(j))
#print(instruct)



data = [0]
data_pointer = 0
start_loop_pointer = []
register = None
instruct_pointer = 0

while instruct_pointer < len(instruct):
  instruct_pointer = exec(instruct[instruct_pointer],instruct_pointer)