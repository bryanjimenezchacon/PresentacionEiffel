note

class
	PANTALLAPRINCIPAL

inherit
	WEL_FRAME_WINDOW
		redefine
			class_background,
			on_paint
		end

create
	make

feature -- Inicio

	make
			-- Crea la ventana
		do
			make_top ("Presentacion Eiffel")
		end

feature {NONE} -- Implementacion

	on_paint (paint_dc: WEL_PAINT_DC; invalid_rect: WEL_RECT)
			-- Centar el texto
		do
			paint_dc.draw_centered_text ("Hola Mundo en Eiffel!",
				client_rect)
		end

	class_background: WEL_WHITE_BRUSH
			-- Fondo Blanco
		once
			create Result.make
		end


end -- class MAIN_WINDOW

