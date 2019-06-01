# SQLSerialGenerator

I created this little project to support myself in inserting data into databases, 
but when i see potential for serial generating i realise, that it's a nice idea to impove it
into nice and elegant program for serial, fast generating.

My ideas to add soon:

	- Add support for huge files, that cannot be load for memory at once

	- Go into CSV standard

	- Remove need to select output file, instead add select directory and name option, 
		so there will be no need to prepare empty file

	- Simple connection for SQLite and MySQL databases, so you can easly execute all querries at once

Actual Instruction:

	- Create CSV file with your data, and modify it by:

		- Adding your separation sign in first line at the beginning and at the end

		- Adding '!END' at the end of your file (in new line)

	- Create output file (WARNING: data from ths file will be ereased)

	- When you're ready, select both files and now you can type querry.

	- If u need short instruction click HELP. Here i will provide some examples on data:


			;id;name;surname;country;phone;sex;
			1;kris;smith;Poland;123456789;M;
			!END

	Ex.: INSERT INTO users VALUES(::0);
	Res.: INSERT INTO users VALUES('1', 'kris', 'smith', 'Poland', '123456789', 'M');

	Ex.: INSERT INTO clients VALUES('::2', '::3', ::5);
	Res.: INSERT INTO clients VALUES('kris', 'smith', 123456789);

	Warning: If you have more than 9 rows, the format for replace gonna change:

			::<NUMBER> -> ::x<NUMBER>

	So for data like:

		;id;productName;isLiq;isSol;idMov;isExis;isGreen;isRed;isBlue;isIs;isNotIs;
		;12;something;1;1;0;0;1;0;1;0;1;
		!END

	Ex.: INSERT INTO products VALUES(::1, '::2', ::5, ::x10, ::x11);
	Res.: INSERT INTO products VALUES(12, 'something', 0, 1, 1);


	- When template is finished you can click example, and program will generate how your querry
		will look like for first row (of data).

	- After you make sure everythnk is done, just click generate.

	- Now you have your querries ready.


If u have any troubles or ideas what can i add into this miniProject mail me:

	raidgar98@onet.pl

with Title: [GitHub] SQLSerialGenerator

so my email filter can filter it from SPAM to another directory :)
