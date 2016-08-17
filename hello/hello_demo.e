note

class
	HOLAMUNDO

inherit
	WEL_APPLICATION

create
	make

feature

	main_window: PANTALLAPRINCIPAL
			-- Crea la ventana principal
		once
			create Result.make
		end

note

end -- class HELLO_DEMO

