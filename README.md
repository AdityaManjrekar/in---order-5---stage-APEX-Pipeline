# in---order-5---stage-APEX-Pipeline
Pipeline	stages
•
Fetch
o
Select	next	instruction	from	program	store
•
Decode
o
Look	up	register	source	opera
nds	from	register	file
o
Resolve	conditional	branches
o
Command	Fetch	to	perform	branch	(and	any	necessary	squashing)
•
Execute
o
Perform	arithmetic
o
Compute	memory	address
•
Memory
o
Read	or	write	data	memory
•


instructions:
•
ADD	<
dest	
register>,	<register>,	<register	or	literal>
•
SUB	<
dest	
register>,	<register>,	<register	or	literal>
•
AND	<
dest	
register>,	<register>,	<register	or	literal>
•
OR	<
dest	
register>,	<register>,	<register	or	literal>
•
XOR	<
dest	
register>,	<register>,	<register	or	literal>
•
MOVC	<
dest	
register>,	<literal>
•
LOAD	<data
register>,	<address	register>,	<literal	offset>
•
STORE	<data	register>,	<address	register>,	<literal	offset>
•
BZ	<literal	offset>
•
BNZ	<literal	offset>
•
JUMP	<absolute	instruction	address>
•
BAL	<absolute	instruction	address>
•
HALT
•
NOP
Writeback
o
Store	arithmetic	or	LOAD	result	into	register	
file
The	MOVC	instruction	
copies	a	constant	into	a	register.
BZ	and	BNZ	require	a	signed	offset.		The	jump	target	address	is	computed	as	(offset	
+	PC).
These	instructions	have	an	implicit	dependency	on	the	target	register	of	the	
instructions	immediately	preceding.		For	instance,	
in	the	following	instruction	
sequence,	the	BZ	branch	will	be	taken
(PC	:=	PC
-
8)
if	R3	is	assigned	a	zero	value:
SUB	R3,	R5,	R6
BZ	
-
8
JUMP	and	BAL	instructions	take	absolute	instruction	addresses.
BAL	is	the	“branch	and	link”	instruction	that	makes	subr
outine	calls.		The	return	
address	(address	of	the	instruction	following	the	BAL)	is	stored	in	a	special	X	
register,	and	then	execution	diverts	to	the	target	address.		The	return	instruction	is	
implemented	as	“JUMP	X”.
BZ,	BNZ,	JUMP,	and	BAL	instructions	d
o	not	have	delay	slots.		Fetched	instructions	in	
the	fall
-
through	must	be	discarded	for	taken	branches.
When	squashing,	the	PC	is	
reset	on	the	same	cycle	as	squashing	so	that	the	target	instruction	is	fetched	on	the	
next	cycle,	resulting	in	a	one
-
cycle	bu
bble	for	every	taken	branch.
HALT	waits	until	the	pipeline	has	completely	drained	and	then	stops	execution.
The	NOP	performs	no	action,	but	the	pipeline	does	advance	one	cycle.
Note:		If	
execution	runs	off	the	end	
of	the	program,	automatically	issue	NOP
instructions	
(instead	of	crashing).
Parsing
When	parsing	instructions,	handle	any	number	of	spaces	between	terminals,	and	
commas	should	be	optional.		Additionally,	accept	literal	numbers	with	and	without	
“#”	prefix.
Suggestion:		When	reading	in	your	
assembly	language	program,	fully	parse	it	at	this	
time,	converting	instructions	to	data	structures.
Instruction	addressing
Since	there	is	no	binary	instruction	format,	this	processor	has	no	concept	of	an	
instruction	memory.		To	give	instructions	addresses
,	we	will	associate	the	first	
i
nstruction	with	address	20000
.		Therefore:
•
The	first
instruction	is	at	address	20000
•
The	second	instruction	
is	at	address	20001
•
And	so	forth...
Data	addressing
Data	memory	starts	at	address	0	and	ends	at	address	9999.
Registe
rs
There	are	eight	architectural	registers,	R0	through	R7.
Command	interface
Your	simulator	should	be	interactive	and	support	the	following	commands	(which	
you	may	accept	in	abbreviated	form):
•
l
oad	<filename>
--
Read	in	assembly	language	code
•
i
nitialize
-
-
Initializes	the	simulator	state,	sets	the	PC	of	the	fetch	stage	to	
point	to	the	first	instruction	in	the	
ASCII
code	file,	which	is	assumed	to	be	at	
address	20000.	
•
s
imulate	<n>
--
Run	simulator	for	
n
cycles	and	then	wait	for	more	input.		
Simulation	may	s
top	earlier	if	a	HALT	instruction	is	encountered.
•
d
isplay
--
Displays	the	contents	of	each	stage	in	the	pipeline	and	the	contents	
of	the	first	100	
data	
memory	locations	containi
ng	data,	starting	with	address	
zero
.	
