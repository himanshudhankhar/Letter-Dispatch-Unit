cmake_minimum_required(VERSION 2.8)
project(LDS)
add_compile_options(-std=c++11)
set(CMAKE_CXX_STANDARD 11)



add_executable(LDS 
		addletter.cpp
		addletter.h
		admin.cpp
		admin.h
		complain.cpp
		complain.h
		Date.h
		error.h
		generateReport.h
		generateReport.cpp
		instituteMemberDatabase.cpp
		instituteMemberDatabase.h
		LetterDatabase.h
		LetterDatabase.cpp
		Letter_status.cpp
		Letter_status.h
		login.cpp
		password.h
		payment.h
		payment.cpp
		post_letter.cpp
		post_letter.h
		updateDataBase.cpp
		updateDataBase.h
		util.h
		
		)

