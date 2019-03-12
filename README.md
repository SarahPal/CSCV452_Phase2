# CSCV452_Phase2
# Group Members: Sarah Palenik & Duncan Emrie
# Developed on Linux Mint System
# Test Cases: 

#   Test00: 

starting test 00 ....

start2(): started
All processes completed.

#   Test01: 
starting test 01 ....

start2(): started
start2(): MailBoxCreate returned id = 7
start2(): MailBoxCreate returned id = 8
All processes completed.

#   Test02: 

starting test 02 ....

start2(): started, trying to create too many mailboxes...
start2(): MailBoxCreate returned id less than zero, id = -1
start2(): MailBoxCreate returned id less than zero, id = -1
start2(): MailBoxCreate returned id less than zero, id = -1
start2(): MailBoxCreate returned id less than zero, id = -1
start2(): MailBoxCreate returned id less than zero, id = -1
start2(): MailBoxCreate returned id less than zero, id = -1
start2(): MailBoxCreate returned id less than zero, id = -1
start2(): MailBoxCreate returned id less than zero, id = -1
start2(): MailBoxCreate returned id less than zero, id = -1
start2(): MailBoxCreate returned id less than zero, id = -1
All processes completed.

#   Test03: 
starting test 03 ....

start2(): started
start2(): MboxCreate returned id = 7
start2(): sending message to mailbox 7
start2(): after send of message, result = 0
start2(): attempting to receive message from mailbox 7
start2(): after receive of message, result = 12 message is 'hello there'
All processes completed.

#   Test04: 

starting test 04 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp1(): started
XXp1(): sending message to mailbox 7
XXp1(): after send of message, result = 0
start2(): joined with kid 4, status = -3
XXp2(): started
XXp2(): receiving message from mailbox 7
XXp2(): after receipt of message, result = 12
        message = 'hello there'
start2(): joined with kid 5, status = -4
All processes completed.

#   Test05: 

starting test 05 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp2(): started
XXp2(): receiving message from mailbox 7
XXp1(): started
XXp1(): sending message to mailbox 7
XXp2(): after receipt of message, result = 12
        message = 'hello there'
start2(): joined with kid 5, status = -4
XXp1(): after send of message, result = 0
start2(): joined with kid 4, status = -3
All processes completed.

#   Test06:

starting test 06 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp1(): started
XXp1(): sending message #0 to mailbox 7
XXp1(): after send of message #0, result = 0
XXp1(): sending message #1 to mailbox 7
XXp1(): after send of message #1, result = 0
XXp1(): sending message #2 to mailbox 7
XXp1(): after send of message #2, result = 0
XXp1(): sending message #3 to mailbox 7
XXp1(): after send of message #3, result = 0
XXp1(): sending message #4 to mailbox 7
XXp1(): after send of message #4, result = 0
XXp1(): sending message #5 to mailbox 7
XXp2(): started
XXp2(): receiving message #0 from mailbox 7
XXp1(): after send of message #5, result = 0
start2(): joined with kid 4, status = -3
XXp2(): after receipt of message #0, result = 16
        message = 'hello there, #0'
XXp2(): receiving message #1 from mailbox 7
XXp2(): after receipt of message #1, result = 16
        message = 'hello there, #1'
XXp2(): receiving message #2 from mailbox 7
XXp2(): after receipt of message #2, result = 16
        message = 'hello there, #2'
XXp2(): receiving message #3 from mailbox 7
XXp2(): after receipt of message #3, result = 16
        message = 'hello there, #3'
XXp2(): receiving message #4 from mailbox 7
XXp2(): after receipt of message #4, result = 16
        message = 'hello there, #4'
XXp2(): receiving message #5 from mailbox 7
XXp2(): after receipt of message #5, result = 16
        message = 'hello there, #5'
start2(): joined with kid 5, status = -4
All processes completed.

#   Test07:

starting test 07 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp1(): started
XXp1(): sending message #0 to mailbox 7
XXp1(): after send of message #0, result = 0
XXp1(): sending message #1 to mailbox 7
XXp1(): after send of message #1, result = 0
XXp1(): sending message #2 to mailbox 7
XXp1(): after send of message #2, result = 0
XXp1(): sending message #3 to mailbox 7
XXp1(): after send of message #3, result = 0
XXp1(): sending message #4 to mailbox 7
XXp1(): after send of message #4, result = 0
start2(): joined with kid 4, status = -3
XXp2a(): sending message 'hello from XXp2a' to mailbox 7, msg_size = 17
XXp2b(): sending message 'hello from XXp2b' to mailbox 7, msg_size = 17
XXp2c(): sending message 'hello from XXp2c' to mailbox 7, msg_size = 17
XXp3(): started
XXp3(): receiving message #0 from mailbox 7
XXp2a(): after send of message 'hello from XXp2a', result = 0
start2(): joined with kid 5, status = -3
XXp3(): after receipt of message #0, result = 16
        message = 'hello there, #0'
XXp3(): receiving message #1 from mailbox 7
XXp2b(): after send of message 'hello from XXp2b', result = 0
start2(): joined with kid 6, status = -3
XXp3(): after receipt of message #1, result = 16
        message = 'hello there, #1'
XXp3(): receiving message #2 from mailbox 7
XXp2c(): after send of message 'hello from XXp2c', result = 0
start2(): joined with kid 7, status = -3
XXp3(): after receipt of message #2, result = 16
        message = 'hello there, #2'
XXp3(): receiving message #3 from mailbox 7
XXp3(): after receipt of message #3, result = 16
        message = 'hello there, #3'
XXp3(): receiving message #4 from mailbox 7
XXp3(): after receipt of message #4, result = 16
        message = 'hello there, #4'
XXp3(): receiving message #5 from mailbox 7
XXp3(): after receipt of message #5, result = 17
        message = 'hello from XXp2a'
XXp3(): receiving message #6 from mailbox 7
XXp3(): after receipt of message #6, result = 17
        message = 'hello from XXp2b'
XXp3(): receiving message #7 from mailbox 7
XXp3(): after receipt of message #7, result = 17
        message = 'hello from XXp2c'
start2(): joined with kid 8, status = -4
All processes completed.

#   Test08:

starting test 08 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp1(): started
XXp1(): sending message #0 to mailbox 7
XXp1(): after send of message #0, result = 0
XXp1(): sending message #1 to mailbox 7
XXp1(): after send of message #1, result = 0
XXp1(): sending message #2 to mailbox 7
XXp1(): after send of message #2, result = 0
XXp1(): sending message #3 to mailbox 7
XXp1(): after send of message #3, result = 0
XXp1(): sending message #4 to mailbox 7
XXp1(): after send of message #4, result = 0
start2(): joined with kid 4, status = -3
XXp2a(): sending message 'hello from XXp2a' to mailbox 7, msg_size = 17
XXp2b(): sending message 'hello from XXp2b' to mailbox 7, msg_size = 17
XXp2c(): sending message 'hello from XXp2c' to mailbox 7, msg_size = 17
XXp3(): started
XXp2a(): after send of message 'hello from XXp2a', result = -3
XXp2a(): zap'd by MboxSend() call
start2(): joined with kid 5, status = -3
XXp2b(): after send of message 'hello from XXp2b', result = -3
XXp2b(): zap'd by MboxSend() call
start2(): joined with kid 6, status = -3
XXp2c(): after send of message 'hello from XXp2c', result = -3
XXp2c(): zap'd by MboxSend() call
start2(): joined with kid 7, status = -3
XXp3(): MboxRelease returned 0
start2(): joined with kid 8, status = -4
All processes completed.

#   Test09: 

starting test 09 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp1(): started
XXp1(): sending message #0 to mailbox 7
XXp1(): after send of message #0, result = 0
XXp1(): sending message #1 to mailbox 7
XXp1(): after send of message #1, result = 0
XXp1(): sending message #2 to mailbox 7
XXp1(): after send of message #2, result = 0
XXp1(): sending message #3 to mailbox 7
XXp1(): after send of message #3, result = 0
XXp1(): sending message #4 to mailbox 7
XXp1(): after send of message #4, result = 0
start2(): joined with kid 4, status = -3
XXp2a(): sending message 'hello from XXp2a' to mailbox 7, msg_size = 17
XXp2b(): sending message 'hello from XXp2b' to mailbox 7, msg_size = 17
XXp2c(): sending message 'hello from XXp2c' to mailbox 7, msg_size = 17
XXp4(): started and quitting
XXp3(): started
XXp3(): MboxRelease returned 0
start2(): joined with kid 9, status = -4
XXp2a(): after send of message 'hello from XXp2a', result = -3
XXp2a(): zap'd by MboxSend() call
start2(): joined with kid 5, status = -3
XXp2b(): after send of message 'hello from XXp2b', result = -3
XXp2b(): zap'd by MboxSend() call
start2(): joined with kid 6, status = -3
XXp2c(): after send of message 'hello from XXp2c', result = -3
XXp2c(): zap'd by MboxSend() call
start2(): joined with kid 7, status = -3
All processes completed.

#   Test10: 

starting test 10 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp1(): started
XXp1(): sending message #0 to mailbox 7
XXp1(): after send of message #0, result = 0
XXp1(): sending message #1 to mailbox 7
XXp1(): after send of message #1, result = 0
XXp1(): sending message #2 to mailbox 7
XXp1(): after send of message #2, result = 0
XXp1(): sending message #3 to mailbox 7
XXp1(): after send of message #3, result = 0
XXp1(): sending message #4 to mailbox 7
XXp1(): after send of message #4, result = 0
start2(): joined with kid 4, status = -3
XXp2a(): conditionally sending message 'hello from XXp2a' to mailbox 7, msg_size = 17
XXp2a(): after conditional send of message 'hello from XXp2a', result = -2
start2(): joined with kid 5, status = -3
XXp2b(): sending message 'hello from XXp2b' to mailbox 7, msg_size = 17
XXp2c(): conditionally sending message 'hello from XXp2c' to mailbox 7, msg_size = 17
XXp2c(): after conditional send of message 'hello from XXp2c', result = -2
start2(): joined with kid 7, status = -3
XXp3(): started
XXp3(): receiving message #0 from mailbox 7
XXp2b(): after send of message 'hello from XXp2b', result = 0
start2(): joined with kid 6, status = -3
XXp3(): after receipt of message #0, result = 16
        message = 'hello there, #0'
XXp3(): receiving message #1 from mailbox 7
XXp3(): after receipt of message #1, result = 16
        message = 'hello there, #1'
XXp3(): receiving message #2 from mailbox 7
XXp3(): after receipt of message #2, result = 16
        message = 'hello there, #2'
XXp3(): receiving message #3 from mailbox 7
XXp3(): after receipt of message #3, result = 16
        message = 'hello there, #3'
XXp3(): receiving message #4 from mailbox 7
XXp3(): after receipt of message #4, result = 16
        message = 'hello there, #4'
XXp3(): receiving message #5 from mailbox 7
XXp3(): after receipt of message #5, result = 17
        message = 'hello from XXp2b'
start2(): joined with kid 8, status = -4
All processes completed.

#   Test11: 

starting test 11 ....

start2(): started
start2(): MboxCreate returned id = 7
start2(): MboxCreate returned id = 8
XXp1(): started
XXp1(): conditionally sending message #0 to mailbox 7
XXp1(): after conditional send of message #0, result = 0
XXp1(): conditionally sending message #1 to mailbox 7
XXp1(): after conditional send of message #1, result = 0
XXp1(): conditionally sending message #2 to mailbox 7
XXp1(): after conditional send of message #2, result = 0
XXp1(): conditionally sending message #3 to mailbox 7
XXp1(): after conditional send of message #3, result = 0
XXp1(): conditionally sending message #4 to mailbox 7
XXp1(): after conditional send of message #4, result = 0
XXp1(): conditionally sending message #5 to mailbox 7
XXp1(): after conditional send of message #5, result = -2
XXp1(): conditionally sending message #6 to mailbox 7
XXp1(): after conditional send of message #6, result = -2
XXp1(): conditionally sending message #7 to mailbox 7
XXp1(): after conditional send of message #7, result = -2
XXp3(): started
XXp3(): receiving message #0 from mailbox 7
XXp3(): after receipt of message #0, result = 16
        message = 'hello there, #0'
XXp3(): receiving message #1 from mailbox 7
XXp3(): after receipt of message #1, result = 16
        message = 'hello there, #1'
XXp3(): receiving message #2 from mailbox 7
XXp3(): after receipt of message #2, result = 16
        message = 'hello there, #2'
XXp3(): receiving message #3 from mailbox 7
XXp3(): after receipt of message #3, result = 16
        message = 'hello there, #3'
XXp3(): receiving message #4 from mailbox 7
XXp3(): after receipt of message #4, result = 16
        message = 'hello there, #4'
XXp1(): conditionally sending message #0 to mailbox 7
XXp1(): after conditional send of message #0, result = 0
XXp1(): conditionally sending message #1 to mailbox 7
XXp1(): after conditional send of message #1, result = 0
XXp1(): conditionally sending message #2 to mailbox 7
XXp1(): after conditional send of message #2, result = 0
XXp1(): conditionally sending message #3 to mailbox 7
XXp1(): after conditional send of message #3, result = 0
XXp1(): conditionally sending message #4 to mailbox 7
XXp1(): after conditional send of message #4, result = 0
XXp1(): conditionally sending message #5 to mailbox 7
XXp1(): after conditional send of message #5, result = -2
XXp1(): conditionally sending message #6 to mailbox 7
XXp1(): after conditional send of message #6, result = -2
XXp1(): conditionally sending message #7 to mailbox 7
XXp1(): after conditional send of message #7, result = -2
start2(): joined with kid 4, status = -3
XXp3(): receiving message #0 from mailbox 7
XXp3(): after receipt of message #0, result = 13
        message = 'good-bye, #0'
XXp3(): receiving message #1 from mailbox 7
XXp3(): after receipt of message #1, result = 13
        message = 'good-bye, #1'
XXp3(): receiving message #2 from mailbox 7
XXp3(): after receipt of message #2, result = 13
        message = 'good-bye, #2'
XXp3(): receiving message #3 from mailbox 7
XXp3(): after receipt of message #3, result = 13
        message = 'good-bye, #3'
XXp3(): receiving message #4 from mailbox 7
XXp3(): after receipt of message #4, result = 13
        message = 'good-bye, #4'
start2(): joined with kid 5, status = -4
All processes completed.

#   Test12:

starting test 12 ....

start2(): started
start2(): MboxCreate returned id = 7
start2(): MboxCreate returned id = 8
XXp1(): started
XXp1(): conditionally sending message #0 to mailbox 7
XXp1(): after conditional send of message #0, result = 0
XXp1(): conditionally sending message #1 to mailbox 7
XXp1(): after conditional send of message #1, result = 0
XXp1(): conditionally sending message #2 to mailbox 7
XXp1(): after conditional send of message #2, result = 0
XXp1(): conditionally sending message #3 to mailbox 7
XXp1(): after conditional send of message #3, result = 0
XXp1(): conditionally sending message #4 to mailbox 7
XXp1(): after conditional send of message #4, result = 0
XXp1(): conditionally sending message #5 to mailbox 7
XXp1(): after conditional send of message #5, result = -2
XXp1(): conditionally sending message #6 to mailbox 7
XXp1(): after conditional send of message #6, result = -2
XXp1(): conditionally sending message #7 to mailbox 7
XXp1(): after conditional send of message #7, result = -2
XXp3(): started
XXp3(): conditionally received message #0 from mailbox 7
        message = 'hello there, #0'
XXp3(): conditionally received message #0 from mailbox 7
        message = 'hello there, #1'
XXp3(): conditionally received message #0 from mailbox 7
        message = 'hello there, #2'
XXp3(): conditionally received message #0 from mailbox 7
        message = 'hello there, #3'
XXp3(): conditionally received message #0 from mailbox 7
        message = 'hello there, #4'
XXp3(): After loop, result is negative; result = -2
XXp3(): received 5 hello messages from mailbox 7
XXp1(): conditionally sending message #0 to mailbox 7
XXp1(): after conditional send of message #0, result = 0
XXp1(): conditionally sending message #1 to mailbox 7
XXp1(): after conditional send of message #1, result = 0
XXp1(): conditionally sending message #2 to mailbox 7
XXp1(): after conditional send of message #2, result = 0
XXp1(): conditionally sending message #3 to mailbox 7
XXp1(): after conditional send of message #3, result = 0
XXp1(): conditionally sending message #4 to mailbox 7
XXp1(): after conditional send of message #4, result = 0
XXp1(): conditionally sending message #5 to mailbox 7
XXp1(): after conditional send of message #5, result = -2
XXp1(): conditionally sending message #6 to mailbox 7
XXp1(): after conditional send of message #6, result = -2
XXp1(): conditionally sending message #7 to mailbox 7
XXp1(): after conditional send of message #7, result = -2
start2(): joined with kid 4, status = -3
XXp3(): conditionally received message #0 from mailbox 7
        message = 'good-bye, #0', result = 13
XXp3(): conditionally received message #0 from mailbox 7
        message = 'good-bye, #1', result = 13
XXp3(): conditionally received message #0 from mailbox 7
        message = 'good-bye, #2', result = 13
XXp3(): conditionally received message #0 from mailbox 7
        message = 'good-bye, #3', result = 13
XXp3(): conditionally received message #0 from mailbox 7
        message = 'good-bye, #4', result = 13
XXp3(): After loop, result is negative; result = -2
XXp3(): received 5 good-bye messages from mailbox 7
start2(): joined with kid 5, status = -4
All processes completed.

#   Test13:

starting test 13 ....

start2(): at beginning, pid = 3
start2(): fork'd child 4
XXp1(): started, calling waitdevice for clock
XXp1(): after waitdevice call
XXp1(): status = 0
start2(): joined with kid 4, status = -3
All processes completed.

#   Test14:

starting test 14 ....

start2(): started
start2(): calling device_output to enable receive interrupts, control = 2
XXp1(): started, calling waitdevice for terminal 1
XXp1(): after waitdevice call
XXp1(): status = 18433
XXp1(): receive status for terminal 1 = 1
XXp1(): character received = H
start2(): joined with kid 4, status = -3
All processes completed.

#   Test15:

starting test 15 ....

start2(): started
start2(): MboxCreate returned id = 7
start2(): sending message to mailbox 7
start2(): after send of message, result = -1
message too big
All processes completed.

#   Test16:

starting test 16 ....

start2(): started, trying to exceed mailslots...
finally the slots are over at mailbox 45 and slot 25
All processes completed.

#   Test17:

starting test 17 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp2a(): sending message 'hello from XXp2a' to mailbox 7, msg_size = 17
XXp2b(): sending message 'hello from XXp2b' to mailbox 7, msg_size = 17
XXp2c(): sending message 'hello from XXp2c' to mailbox 7, msg_size = 17
XXp4(): started and quitting
XXp3(): started
XXp3(): MboxRelease returned 0
start2(): joined with kid 8, status = -4
XXp2a(): after send of message 'hello from XXp2a', result = -3
XXp2a(): zap'd by MboxSend() call
start2(): joined with kid 4, status = -3
XXp2b(): after send of message 'hello from XXp2b', result = -3
XXp2b(): zap'd by MboxSend() call
start2(): joined with kid 5, status = -3
XXp2c(): after send of message 'hello from XXp2c', result = -3
XXp2c(): zap'd by MboxSend() call
start2(): joined with kid 6, status = -3
All processes completed.

#   Test18:

starting test 18 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp4(): started and quitting
XXp3(): started
XXp3(): MboxRelease returned 0
start2(): joined with kid 8, status = -4
XXp2a(): after recv of message '', result = -3
XXp2a(): zap'd by MboxReceive() call
start2(): joined with kid 4, status = -3
XXp2b(): after recv of message '', result = -3
XXp2b(): zap'd by MboxReceive() call
start2(): joined with kid 5, status = -3
XXp2c(): after recv of message '', result = -3
XXp2c(): zap'd by MboxReceive() call
start2(): joined with kid 6, status = -3
All processes completed.

#   Test19:

starting test 19 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp2a(): sending message 'hello from XXp2a' to mailbox 7, msg_size = 17
XXp2b(): sending message 'hello from XXp2b' to mailbox 7, msg_size = 17
XXp2c(): sending message 'hello from XXp2c' to mailbox 7, msg_size = 17
XXp4(): started and quitting
XXp3(): started
XXp3(): MboxRelease returned 0
start2(): joined with kid 8, status = -4
XXp2a(): after send of message 'hello from XXp2a', result = -3
XXp2a(): zap'd by MboxSend() call
start2(): joined with kid 4, status = -3
XXp2b(): after send of message 'hello from XXp2b', result = -3
XXp2b(): zap'd by MboxSend() call
start2(): joined with kid 5, status = -3
XXp2c(): after send of message 'hello from XXp2c', result = -3
XXp2c(): zap'd by MboxSend() call
start2(): joined with kid 6, status = -3
failed to send to released mailbox ... success
All processes completed.

#   Test20:

starting test 20 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp2a(): receiving message from mailbox 7, msg_size = 1
XXp2b(): receiving message from mailbox 7, msg_size = 1
XXp2c(): receiving message from mailbox 7, msg_size = 1
XXp4(): started and quitting
XXp3(): started
XXp3(): MboxRelease returned 0
start2(): joined with kid 8, status = -4
XXp2a(): after receive of message, result = -3
XXp2a(): zap'd by MboxReceive() call
start2(): joined with kid 4, status = -3
XXp2b(): after receive of message, result = -3
XXp2b(): zap'd by MboxReceive() call
start2(): joined with kid 5, status = -3
XXp2c(): after receive of message, result = -3
XXp2c(): zap'd by MboxReceive() call
start2(): joined with kid 6, status = -3
failed to recv from released mailbox ... success
All processes completed.

#   Test21:

starting test 21 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp1(): started
XXp1(): sending message #0 to mailbox 7
XXp2(): started
XXp2(): receiving message #0 from mailbox 7
XXp1(): after send of message #0, result = 0
XXp1(): sending message #1 to mailbox 7
XXp2(): after receipt of message #0, result = 16
        message = 'hello there, #0'
XXp2(): receiving message #1 from mailbox 7
XXp1(): after send of message #1, result = 0
start2(): joined with kid 4, status = -3
XXp2(): after receipt of message #1, result = 16
        message = 'hello there, #1'
start2(): joined with kid 5, status = -4
All processes completed.

#   Test22:

starting test 22 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp2(): started
XXp2(): receiving message #0 from mailbox 7
XXp1(): started
XXp1(): sending message #0 to mailbox 7
XXp2(): after receipt of message #0, result = 16
        message = 'hello there, #0'
XXp2(): receiving message #1 from mailbox 7
XXp1(): after send of message #0, result = 0
XXp1(): sending message #1 to mailbox 7
XXp2(): after receipt of message #1, result = 16
        message = 'hello there, #1'
start2(): joined with kid 5, status = -4
XXp1(): after send of message #1, result = 0
start2(): joined with kid 4, status = -3
All processes completed.

#   Test23:

starting test 23 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp3(): started
XXp3(): fork'ing XXp2 at priority 4
XXp2(): started
XXp2(): priority 4, receiving message from mailbox 7
XXp3(): fork'ing XXp2 at priority 2
XXp2(): started
XXp2(): priority 2, receiving message from mailbox 7
XXp3(): fork'ing XXp2 at priority 2
XXp2(): started
XXp2(): priority 2, receiving message from mailbox 7
XXp3(): fork'ing XXp1 at priority 1
XXp1(): started
XXp1(): sending message #1 to mailbox 7
XXp1(): sending message #2 to mailbox 7
XXp1(): sending message #3 to mailbox 7
XXp2(): priority 2, after receipt of message, result = 15
        message = 'Second message'
XXp2(): priority 2, after receipt of message, result = 14
        message = 'Third message'
XXp2(): priority 4, after receipt of message, result = 14
        message = 'First message'
XXp3(): join'd with child 8 whose status is -1
XXp3(): join'd with child 6 whose status is -2
XXp3(): join'd with child 7 whose status is -2
XXp3(): join'd with child 5 whose status is -4
start2(): joined with kid 4, status = -5
All processes completed.

#   Test24:

starting test 24 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp3(): started, about to send 5 messages to the mailbox
XXp3(): sending message #1 to mailbox 7
XXp3(): sending message #2 to mailbox 7
XXp3(): sending message #3 to mailbox 7
XXp3(): sending message #4 to mailbox 7
XXp3(): sending message #5 to mailbox 7
XXp3(): fork'ing XXp2 at priority 4
XXp2(): started
XXp2(): priority 4, sending message to mailbox 7
XXp3(): fork'ing XXp2 at priority 3
XXp2(): started
XXp2(): priority 3, sending message to mailbox 7
XXp3(): fork'ing XXp2 at priority 2
XXp2(): started
XXp2(): priority 2, sending message to mailbox 7
XXp3(): fork'ing XXp1 at priority 1
XXp1(): started
XXp1(): received message #1 containing: First message
XXp1(): received message #2 containing: Second message
XXp1(): received message #3 containing: Third message
XXp1(): received message #4 containing: Fourth message
XXp1(): received message #5 containing: Fifth message
XXp1(): received message #6 containing: Sixth message
XXp1(): received message #7 containing: Seventh message
XXp1(): received message #8 containing: Eighth message
XXp2(): priority 2, after sending message, result = 0
XXp2(): priority 3, after sending message, result = 0
XXp2(): priority 4, after sending message, result = 0
XXp3(): join'd with child 8 whose status is -1
XXp3(): join'd with child 7 whose status is -2
XXp3(): join'd with child 6 whose status is -3
XXp3(): join'd with child 5 whose status is -4
start2(): joined with kid 4, status = -5
All processes completed.

#   Test25:

starting test 25 ....

start2(): started, trying to create too many mailboxes...
start2(): MailBoxCreate returned id less than zero, id = -1
start2(): MailBoxCreate returned id less than zero, id = -1
start2(): calling MboxRelease(0)
start2(): calling MboxRelease(0) returned 0
start2(): calling MboxRelease(1)
start2(): calling MboxRelease(1) returned 0
start2(): calling MboxRelease(2)
start2(): calling MboxRelease(2) returned 0
start2(): calling MboxRelease(3)
start2(): calling MboxRelease(3) returned 0
start2(): calling MboxRelease(4)
start2(): calling MboxRelease(4) returned 0
start2(): calling MboxRelease(5)
start2(): calling MboxRelease(5) returned 0
start2(): MailBoxCreate returned id = 10
start2(): MailBoxCreate returned id = 11
start2(): MailBoxCreate returned id = 12
start2(): MailBoxCreate returned id = 13
start2(): MailBoxCreate returned id = 14
start2(): MailBoxCreate returned id = 15
start2(): MailBoxCreate returned id less than zero, id = -1
start2(): MailBoxCreate returned id less than zero, id = -1
All processes completed.

#   Test26:

starting test 26 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp1(): started
XXp1(): receiving message #0 from mailbox 7
XXp2a(): receive message from mailbox 7, msg_size = 20
XXp2c(): receive message from mailbox 7, msg_size = 20
XXp2b(): receive message from mailbox 7, msg_size = 20
XXp3(): started
XXp1(): after receive of message #0, result = -3
XXp1(): receiving message #1 from mailbox 7
XXp1(): after receive of message #1, result = -1
XXp1(): receiving message #2 from mailbox 7
XXp1(): after receive of message #2, result = -1
XXp1(): receiving message #3 from mailbox 7
XXp1(): after receive of message #3, result = -1
XXp1(): receiving message #4 from mailbox 7
XXp1(): after receive of message #4, result = -1
XXp1(): sending message #0 to mailbox 7
XXp1(): after send of message #0, result = -1
XXp1(): sending message #1 to mailbox 7
XXp1(): after send of message #1, result = -1
XXp1(): sending message #2 to mailbox 7
XXp1(): after send of message #2, result = -1
XXp1(): sending message #3 to mailbox 7
XXp1(): after send of message #3, result = -1
XXp1(): sending message #4 to mailbox 7
XXp1(): after send of message #4, result = -1
start2(): joined with kid 4, status = -3
XXp2a(): after receive of message result = -3
XXp2a(): zap'd by MboxReceive() call
start2(): joined with kid 5, status = -3
XXp2c(): after receive of message result = -3
XXp2c(): zap'd by MboxReceive() call
start2(): joined with kid 7, status = -3
XXp2b(): after receive of message result = -3
XXp2b(): zap'd by MboxReceive() call
start2(): joined with kid 6, status = -3
XXp3(): MboxRelease returned 0
start2(): joined with kid 8, status = -4
All processes completed.

#   Test27:

starting test 27 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp2c(): receive message from mailbox 7, msg_size = 20
XXp2b(): receive message from mailbox 7, msg_size = 20
XXp2a(): receive message from mailbox 7, msg_size = 20
XXp1(): started
XXp1(): receiving message #0 from mailbox 7
XXp4(): started and quitting
XXp3(): started
XXp3(): MboxRelease returned 0
start2(): joined with kid 9, status = -4
XXp2c(): after receive of message result = -3
XXp2c(): zap'd by MboxReceive() call
start2(): joined with kid 7, status = -3
XXp2b(): after receive of message result = -3
XXp2b(): zap'd by MboxReceive() call
start2(): joined with kid 6, status = -3
XXp2a(): after receive of message result = -3
XXp2a(): zap'd by MboxReceive() call
start2(): joined with kid 5, status = -3
XXp1(): after receive of message #0, result = -3
XXp1(): receiving message #1 from mailbox 7
XXp1(): after receive of message #1, result = -1
XXp1(): receiving message #2 from mailbox 7
XXp1(): after receive of message #2, result = -1
XXp1(): receiving message #3 from mailbox 7
XXp1(): after receive of message #3, result = -1
XXp1(): receiving message #4 from mailbox 7
XXp1(): after receive of message #4, result = -1
XXp1(): sending message #0 to mailbox 7
XXp1(): after send of message #0, result = -1
XXp1(): sending message #1 to mailbox 7
XXp1(): after send of message #1, result = -1
XXp1(): sending message #2 to mailbox 7
XXp1(): after send of message #2, result = -1
XXp1(): sending message #3 to mailbox 7
XXp1(): after send of message #3, result = -1
XXp1(): sending message #4 to mailbox 7
XXp1(): after send of message #4, result = -1
start2(): joined with kid 4, status = -3
All processes completed.

#   Test28:

starting test 28 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp2a(): receiving message from mailbox 7, msg_size = 1
XXp2b(): receiving message from mailbox 7, msg_size = 1
XXp2c(): receiving message from mailbox 7, msg_size = 1
XXp3(): started
XXp2a(): after receive of message, result = -3
XXp2a(): zap'd by MboxReceive() call
start2(): joined with kid 4, status = -3
XXp2b(): after receive of message, result = -3
XXp2b(): zap'd by MboxReceive() call
start2(): joined with kid 5, status = -3
XXp2c(): after receive of message, result = -3
XXp2c(): zap'd by MboxReceive() call
start2(): joined with kid 6, status = -3
XXp3(): MboxRelease returned 0
start2(): joined with kid 7, status = -4
failed to recv from released mailbox ... success
All processes completed.

#   Test29:

starting test 29 ....

start2(): started
start2(): MboxCreate returned id = 7
XXp2a(): sending message 'hello from XXp2a' to mailbox 7, msg_size = 17
XXp2b(): sending message 'hello from XXp2b' to mailbox 7, msg_size = 17
XXp2c(): sending message 'hello from XXp2c' to mailbox 7, msg_size = 17
XXp3(): started
XXp2a(): after send of message 'hello from XXp2a', result = -3
XXp2a(): zap'd by MboxSend() call
start2(): joined with kid 4, status = -3
XXp2b(): after send of message 'hello from XXp2b', result = -3
XXp2b(): zap'd by MboxSend() call
start2(): joined with kid 5, status = -3
XXp2c(): after send of message 'hello from XXp2c', result = -3
XXp2c(): zap'd by MboxSend() call
start2(): joined with kid 6, status = -3
XXp3(): MboxRelease returned 0
start2(): joined with kid 7, status = -4
failed to send to released mailbox ... success
All processes completed.

#   Test30:

starting test 30 ....

start2(): started
start2(): MboxCreate returned id = 7
start2(): sending message to mailbox 7
start2(): after send of message, result = 0
XXp3(): sending message to mailbox 7
XXp2(): sending message to mailbox 7
XXp1(): sending message to mailbox 7
XXp4(): Releasing MailBox 7
XXp3(): after send of message, result = -3
XXp2(): after send of message, result = -3
XXp4(): after release of mailbox, result = 0
XXp1(): after send of message, result = -3
All processes completed.

#   Test31:

starting test 31 ....

start2(): started
start2(): MboxCreate returned id = 7
start2(): sending message to mailbox 7
XXp3(): receiving message from mailbox 7, should block
XXp2(): receiving message from mailbox 7 should block
XXp1(): receiving message to mailbox 7 should block
XXp4(): Releasing Mailbox 7
XXp3(): after send of message, result = -3
XXp2(): after send of message, result = -3
XXp4(): after release of mailbox, result = 0
XXp1(): after send of message, result = -3
start2(): after send of message, result = -3
All processes completed.

#   Test32:

starting test 32 ....

start2(): started
start2(): calling device_output to enable receive interrupts, control = 2
XXp0(): started, calling waitdevice for terminal 0
XXp1(): started, calling waitdevice for terminal 1
XXp2(): started, calling waitdevice for terminal 2
XXp3(): started, calling waitdevice for terminal 3
XXp0(): after waitdevice call
XXp0(): status = 23041
XXp0(): receive status for terminal 1 = 1
XXp0(): character received = Z
start2(): joined with kid 4, status = -3

XXp1(): after waitdevice call
XXp1(): status = 18433
XXp1(): receive status for terminal 1 = 1
XXp1(): character received = H
start2(): joined with kid 5, status = -3

XXp2(): after waitdevice call
XXp2(): status = 18177
XXp2(): receive status for terminal 1 = 1
XXp2(): character received = G
start2(): joined with kid 6, status = -3

XXp3(): after waitdevice call
XXp3(): status = 16641
XXp3(): receive status for terminal 1 = 1
XXp3(): character received = A
start2(): joined with kid 7, status = -3

All processes completed.

#   Test33:

starting test 33 ....

start2(): started
start2(): MboxCreate returned id = 7
start2(): sending message to mailbox 7
start2(): after send of message, result = 0
start2(): attempting to receive message from mailbox 7
start2(): after receive of message, result = 12
          message is 'hello there'
All processes completed.

#   Test34:

starting test 34 ....

start2(): started
start2(): MboxCreate returned id = 7
start2(): sending message to mailbox 7
start2(): after send of message, result = -1
start2(): message was too large (expected).
All processes completed.

#   Test35:

starting test 35 ....

start2(): started, creating with slot_size too big
start2(): MailBoxCreate returned id = -1
start2(): passed...
start2(): started, creating with slot_size -1
start2(): MailBoxCreate returned id = -1
start2(): passed...
start2(): started, creating with slot_num -1
start2(): MailBoxCreate returned id = -1
start2(): passed...
start2(): started creating with slot_num 2, slot_size 0
start2(): MailBoxCreate returned id = 7
start2(): passed...
start2(): sending message to mailbox 7
start2(): after send of message, result = 0
start2(): passed...
start2(): sending message to mailbox 7
start2(): after send of message, result = 0
start2(): passed...
start2(): attempting to receive message from mailbox 7
start2(): after receive of message, result = 0
start2(): passed...
start2(): attempting to receive message from mailbox 7
start2(): after receive of message, result = 0
start2(): passed...
All processes completed.

#   Test36:

starting test 36 ....

start2(): putting itself into user mode
start2(): calling usyscall executing syscall 0, this should halt
nullsys(): Invalid syscall 0. Halting...

#   Test37:

starting test 37 ....

start2(): putting itself into user mode
start2(): calling usyscall executing syscall MAXSYSCALLS - 1,
          this should halt
nullsys(): Invalid syscall 49. Halting...

#   Test38:

starting test 38 ....

start2(): putting itself into user mode
start2(): calling usyscall executing syscall 0, this should halt
syscall_handler(): sys number 50 is wrong.  Halting...

#   Test39:

starting test 39 ....

start2(): started
start2(): MboxCreate returned id = 7
start2(): after send of message, result = 0
start2(): Attempting to receive message fm mailbox 7.
          Should fail here because it's receive buffer is
          too small
start2(): after receive of message, result = -1
          message is ''
start2(): got that message was too big. PASSED!
All processes completed.

#   Test40:

starting test 40 ....

start2(): started
start2(): MboxCreate returned id = 7
start2(): Attempting to receive message from mailbox 7
          But it is blocked because the slots are empty.
          Then it should fail due to buffer size too small
XXp1(): started
XXp1(): arg = ''
start2(): after receive of message, result = -1
          message is ''
start2(): got that message was too big. PASSED!
start2(): joining with child
XXp1(): after send of message, result = 0 
All processes completed.

#   Test41:

starting test 41 ....

start2(): started
start2(): MboxCreate returned id = 7
start2(): MboxCreate returned id = 8
XXp1(): started
XXp1(): conditionally sending message #0 to mailbox 7
XXp1(): after conditional send of message #0, result = 0
XXp1(): conditionally sending message #1 to mailbox 7
XXp1(): after conditional send of message #1, result = 0
XXp1(): conditionally sending message #2 to mailbox 7
XXp1(): after conditional send of message #2, result = 0
XXp1(): conditionally sending message #3 to mailbox 7
XXp1(): after conditional send of message #3, result = 0
XXp1(): conditionally sending message #4 to mailbox 7
XXp1(): after conditional send of message #4, result = 0
XXp1(): conditionally sending message #5 to mailbox 7
XXp1(): after conditional send of message #5, result = -2
XXp1(): conditionally sending message #6 to mailbox 7
XXp1(): after conditional send of message #6, result = -2
XXp1(): conditionally sending message #7 to mailbox 7
XXp1(): after conditional send of message #7, result = -2
XXp1(): conditionally sending message #0 to mailbox 7
XXp1(): after conditional send of message #0, result = -2
XXp1(): conditionally sending message #1 to mailbox 7
XXp1(): after conditional send of message #1, result = -2
XXp1(): conditionally sending message #2 to mailbox 7
XXp1(): after conditional send of message #2, result = -2
XXp1(): conditionally sending message #3 to mailbox 7
XXp1(): after conditional send of message #3, result = -2
XXp1(): conditionally sending message #4 to mailbox 7
XXp1(): after conditional send of message #4, result = -2
XXp1(): conditionally sending message #5 to mailbox 7
XXp1(): after conditional send of message #5, result = -2
XXp1(): conditionally sending message #6 to mailbox 7
XXp1(): after conditional send of message #6, result = -2
XXp1(): conditionally sending message #7 to mailbox 7
XXp1(): after conditional send of message #7, result = -2
start2(): joined with kid 4, status = -3
XXp3(): started
XXp3(): conditionally received message #0 from mailbox 7
        message = 'hello there, #0'
XXp3(): conditionally received message #0 from mailbox 7
        message = 'hello there, #1'
XXp3(): conditionally received message #0 from mailbox 7
        message = 'hello there, #2'
XXp3(): conditionally received message #0 from mailbox 7
        message = 'hello there, #3'
XXp3(): conditionally received message #0 from mailbox 7
        message = 'hello there, #4'
XXp3(): After loop, result is negative; result = -2
XXp3(): received 5 hello messages from mailbox 7
XXp3(): After loop, result is negative; result = -2
XXp3(): received 0 good-bye messages from mailbox 7
start2(): joined with kid 5, status = -4
All processes completed.

#   Test42:

starting test 42 ....

start2(): started
start2(): MboxCreate returned id = 7
start2(): forking XXp1
start2(): forking XXp2
XXp1(): started
XXp1(): sending message #0 to mailbox 7
XXp1(): after send of message #0, result = 0
XXp1(): sending message #500 to mailbox 7
XXp1(): after send of message #500, result = 0
XXp1(): sending message #1000 to mailbox 7
XXp1(): after send of message #1000, result = 0
XXp1(): sending message #1201 to mailbox 7
XXp1(): after send of message #1201, result = 0
XXp1(): sending message #1202 to mailbox 7
XXp1(): after send of message #1202, result = 0
XXp1(): sending message #1203 to mailbox 7
XXp1(): after send of message #1203, result = 0
XXp1(): sending message #1204 to mailbox 7
XXp1(): after send of message #1204, result = 0
XXp1(): sending message #1205 to mailbox 7
XXp1(): after send of message #1205, result = 0
XXp1(): sending message #1206 to mailbox 7
XXp1(): after send of message #1206, result = 0
XXp1(): sending message #1207 to mailbox 7
XXp1(): after send of message #1207, result = 0
XXp1(): sending message #1208 to mailbox 7
XXp1(): after send of message #1208, result = 0
XXp1(): sending message #1209 to mailbox 7
XXp1(): after send of message #1209, result = 0
XXp1(): sending message #1210 to mailbox 7
XXp1(): after send of message #1210, result = 0
XXp1(): sending message #1211 to mailbox 7
XXp1(): after send of message #1211, result = 0
XXp1(): sending message #1212 to mailbox 7
XXp1(): after send of message #1212, result = 0
XXp1(): sending message #1213 to mailbox 7
XXp1(): after send of message #1213, result = 0
XXp1(): sending message #1214 to mailbox 7
XXp1(): after send of message #1214, result = 0
XXp1(): sending message #1215 to mailbox 7
XXp1(): after send of message #1215, result = 0
XXp1(): sending message #1216 to mailbox 7
XXp1(): after send of message #1216, result = 0
XXp1(): sending message #1217 to mailbox 7
XXp1(): after send of message #1217, result = 0
XXp1(): sending message #1218 to mailbox 7
XXp1(): after send of message #1218, result = 0
XXp1(): sending message #1219 to mailbox 7
XXp1(): after send of message #1219, result = 0
XXp1(): sending message #1220 to mailbox 7
XXp1(): after send of message #1220, result = 0
XXp1(): sending message #1221 to mailbox 7
XXp1(): after send of message #1221, result = 0
XXp1(): sending message #1222 to mailbox 7
XXp1(): after send of message #1222, result = 0
XXp1(): sending message #1223 to mailbox 7
XXp1(): after send of message #1223, result = 0
XXp1(): sending message #1224 to mailbox 7
XXp1(): after send of message #1224, result = 0
XXp1(): sending message #1225 to mailbox 7
XXp1(): after send of message #1225, result = 0
XXp1(): sending message #1226 to mailbox 7
XXp1(): after send of message #1226, result = 0
XXp1(): sending message #1227 to mailbox 7
XXp1(): after send of message #1227, result = 0
XXp1(): sending message #1228 to mailbox 7
XXp1(): after send of message #1228, result = 0
XXp1(): sending message #1229 to mailbox 7
XXp1(): after send of message #1229, result = 0
XXp1(): sending message #1230 to mailbox 7
XXp1(): after send of message #1230, result = 0
XXp1(): sending message #1231 to mailbox 7
XXp1(): after send of message #1231, result = 0
XXp1(): sending message #1232 to mailbox 7
XXp1(): after send of message #1232, result = 0
XXp1(): sending message #1233 to mailbox 7
XXp1(): after send of message #1233, result = 0
XXp1(): sending message #1234 to mailbox 7
XXp1(): after send of message #1234, result = 0
XXp1(): sending message #1235 to mailbox 7
XXp1(): after send of message #1235, result = 0
XXp1(): sending message #1236 to mailbox 7
XXp1(): after send of message #1236, result = 0
XXp1(): sending message #1237 to mailbox 7
XXp1(): after send of message #1237, result = 0
XXp1(): sending message #1238 to mailbox 7
XXp1(): after send of message #1238, result = 0
XXp1(): sending message #1239 to mailbox 7
XXp1(): after send of message #1239, result = 0
XXp1(): sending message #1240 to mailbox 7
XXp1(): after send of message #1240, result = 0
XXp1(): sending message #1241 to mailbox 7
XXp1(): after send of message #1241, result = 0
XXp1(): sending message #1242 to mailbox 7
XXp1(): after send of message #1242, result = 0
XXp1(): sending message #1243 to mailbox 7
XXp1(): after send of message #1243, result = 0
XXp1(): sending message #1244 to mailbox 7
XXp1(): after send of message #1244, result = 0
XXp1(): sending message #1245 to mailbox 7
XXp1(): after send of message #1245, result = 0
XXp1(): sending message #1246 to mailbox 7
XXp1(): after send of message #1246, result = 0
XXp1(): sending message #1247 to mailbox 7
XXp1(): after send of message #1247, result = 0
XXp1(): sending message #1248 to mailbox 7
XXp1(): after send of message #1248, result = 0
XXp1(): sending message #1249 to mailbox 7
XXp1(): after send of message #1249, result = 0
start2(): joined with kid 4, status = -3
XXp2(): started
XXp2(): sending message #0 to mailbox 7
XXp2(): after send of message #0, result = 0
XXp2(): sending message #500 to mailbox 7
XXp2(): after send of message #500, result = 0
XXp2(): sending message #1000 to mailbox 7
XXp2(): after send of message #1000, result = 0
XXp2(): sending message #1201 to mailbox 7
XXp2(): after send of message #1201, result = 0
XXp2(): sending message #1202 to mailbox 7
XXp2(): after send of message #1202, result = 0
XXp2(): sending message #1203 to mailbox 7
XXp2(): after send of message #1203, result = 0
XXp2(): sending message #1204 to mailbox 7
XXp2(): after send of message #1204, result = 0
XXp2(): sending message #1205 to mailbox 7
XXp2(): after send of message #1205, result = 0
XXp2(): sending message #1206 to mailbox 7
XXp2(): after send of message #1206, result = 0
XXp2(): sending message #1207 to mailbox 7
XXp2(): after send of message #1207, result = 0
XXp2(): sending message #1208 to mailbox 7
XXp2(): after send of message #1208, result = 0
XXp2(): sending message #1209 to mailbox 7
XXp2(): after send of message #1209, result = 0
XXp2(): sending message #1210 to mailbox 7
XXp2(): after send of message #1210, result = 0
XXp2(): sending message #1211 to mailbox 7
XXp2(): after send of message #1211, result = 0
XXp2(): sending message #1212 to mailbox 7
XXp2(): after send of message #1212, result = 0
XXp2(): sending message #1213 to mailbox 7
XXp2(): after send of message #1213, result = 0
XXp2(): sending message #1214 to mailbox 7
XXp2(): after send of message #1214, result = 0
XXp2(): sending message #1215 to mailbox 7
XXp2(): after send of message #1215, result = 0
XXp2(): sending message #1216 to mailbox 7
XXp2(): after send of message #1216, result = 0
XXp2(): sending message #1217 to mailbox 7
XXp2(): after send of message #1217, result = 0
XXp2(): sending message #1218 to mailbox 7
XXp2(): after send of message #1218, result = 0
XXp2(): sending message #1219 to mailbox 7
XXp2(): after send of message #1219, result = 0
XXp2(): sending message #1220 to mailbox 7
XXp2(): after send of message #1220, result = 0
XXp2(): sending message #1221 to mailbox 7
XXp2(): after send of message #1221, result = 0
XXp2(): sending message #1222 to mailbox 7
XXp2(): after send of message #1222, result = 0
XXp2(): sending message #1223 to mailbox 7
XXp2(): after send of message #1223, result = 0
XXp2(): sending message #1224 to mailbox 7
XXp2(): after send of message #1224, result = 0
XXp2(): sending message #1225 to mailbox 7
XXp2(): after send of message #1225, result = 0
XXp2(): sending message #1226 to mailbox 7
XXp2(): after send of message #1226, result = 0
XXp2(): sending message #1227 to mailbox 7
XXp2(): after send of message #1227, result = 0
XXp2(): sending message #1228 to mailbox 7
XXp2(): after send of message #1228, result = 0
XXp2(): sending message #1229 to mailbox 7
XXp2(): after send of message #1229, result = 0
XXp2(): sending message #1230 to mailbox 7
XXp2(): after send of message #1230, result = 0
XXp2(): sending message #1231 to mailbox 7
XXp2(): after send of message #1231, result = 0
XXp2(): sending message #1232 to mailbox 7
XXp2(): after send of message #1232, result = 0
XXp2(): sending message #1233 to mailbox 7
XXp2(): after send of message #1233, result = 0
XXp2(): sending message #1234 to mailbox 7
XXp2(): after send of message #1234, result = 0
XXp2(): sending message #1235 to mailbox 7
XXp2(): after send of message #1235, result = 0
XXp2(): sending message #1236 to mailbox 7
XXp2(): after send of message #1236, result = 0
XXp2(): sending message #1237 to mailbox 7
XXp2(): after send of message #1237, result = 0
XXp2(): sending message #1238 to mailbox 7
XXp2(): after send of message #1238, result = 0
XXp2(): sending message #1239 to mailbox 7
XXp2(): after send of message #1239, result = 0
start2(): joined with kid 5, status = -3
start2(): receiving message #0 from mailbox 7
start2(): result = 24
start2(): message = 'XXp1(): hello there, #0'
start2(): receiving message #1 from mailbox 7
start2(): result = 24
start2(): message = 'XXp1(): hello there, #1'
start2(): receiving message #2 from mailbox 7
start2(): result = 24
start2(): message = 'XXp1(): hello there, #2'
start2(): receiving message #3 from mailbox 7
start2(): result = 24
start2(): message = 'XXp1(): hello there, #3'
start2(): receiving message #4 from mailbox 7
start2(): result = 24
start2(): message = 'XXp1(): hello there, #4'
start2(): receiving message #5 from mailbox 7
start2(): result = 24
start2(): message = 'XXp1(): hello there, #5'
start2(): receiving message #6 from mailbox 7
start2(): result = 24
start2(): message = 'XXp1(): hello there, #6'
start2(): receiving message #7 from mailbox 7
start2(): result = 24
start2(): message = 'XXp1(): hello there, #7'
start2(): receiving message #8 from mailbox 7
start2(): result = 24
start2(): message = 'XXp1(): hello there, #8'
start2(): receiving message #9 from mailbox 7
start2(): result = 24
start2(): message = 'XXp1(): hello there, #9'
start2(): sending message #0 to mailbox 7
start2(): after send of message #0, result = 0
start2(): sending message #1 to mailbox 7
start2(): after send of message #1, result = 0
start2(): sending message #2 to mailbox 7
start2(): after send of message #2, result = 0
start2(): sending message #3 to mailbox 7
start2(): after send of message #3, result = 0
start2(): sending message #4 to mailbox 7
start2(): after send of message #4, result = 0
start2(): sending message #5 to mailbox 7
start2(): after send of message #5, result = 0
start2(): sending message #6 to mailbox 7
start2(): after send of message #6, result = 0
start2(): sending message #7 to mailbox 7
start2(): after send of message #7, result = 0
start2(): sending message #8 to mailbox 7
start2(): after send of message #8, result = 0
start2(): sending message #9 to mailbox 7
start2(): after send of message #9, result = 0
start2(): sending message #10 to mailbox 7
start2(): after send of message #10, result = 0
start2(): sending message #11 to mailbox 7
start2(): after send of message #11, result = 0
start2(): sending message #12 to mailbox 7
start2(): after send of message #12, result = 0
start2(): sending message #13 to mailbox 7
start2(): after send of message #13, result = 0
start2(): sending message #14 to mailbox 7
start2(): after send of message #14, result = 0
start2(): sending message #15 to mailbox 7
start2(): after send of message #15, result = 0
start2(): sending message #16 to mailbox 7
start2(): after send of message #16, result = 0
start2(): sending message #17 to mailbox 7
start2(): after send of message #17, result = 0
start2(): sending message #18 to mailbox 7
start2(): after send of message #18, result = 0
start2(): sending message #19 to mailbox 7
start2(): after send of message #19, result = 0
start2(): sending message #20 to mailbox 7
start2(): this should return -2
start2(): after send of message #20, result = -2
start2(): sending message #21 to mailbox 7
start2(): this should return -2
start2(): after send of message #21, result = -2
start2(): sending message #22 to mailbox 7
start2(): this should return -2
start2(): after send of message #22, result = -2
start2(): sending message #23 to mailbox 7
start2(): this should return -2
start2(): after send of message #23, result = -2
start2(): sending message #24 to mailbox 7
start2(): this should return -2
start2(): after send of message #24, result = -2
All processes completed.
