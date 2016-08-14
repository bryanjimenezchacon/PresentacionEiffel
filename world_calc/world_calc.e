note
	description: "Ejemplo sencillo de una calculadora. Desarrollada para el curso de Lenguajes de Programación."
	status: "See notice at end of class."

class
	CALCU_EIFFEL

inherit
	WINFORMS_FORM
		rename
			make as make_form,
			refresh as refresh_winform
		redefine
			dispose_boolean
		end

	ANY

create
	make

feature {NONE}

	make
			--INICIALIZACION DE COMPONENTES
			-- PUNTO DE ENTRADA
		do
			initialize_components
			{WINFORMS_APPLICATION}.run_form (Current)
		end

feature -- Acceso

	components: SYSTEM_DLL_SYSTEM_CONTAINER
			-- System.ComponentModel.Container.

	btn_igual, btn_borrar: WINFORMS_BUTTON
			-- System.Windows.Forms.Button.

	lista_botones, lista_btns_operaciones: NATIVE_ARRAY [WINFORMS_BUTTON]
			-- Lista de Botones de numeros y operandos.

	txt_formula: WINFORMS_TEXT_BOX
			-- Caja  de Texto de Operacion

	lbl_formula: WINFORMS_LABEL
			-- Etiqueta

feature -- METODOS

	initialize_components
			-- Inicializacion de los componentes.
		local
			l_size: DRAWING_SIZE
			l_point: DRAWING_POINT
			i: INTEGER
		do
			create components.make
			create txt_formula.make
			create lbl_formula.make
			create btn_igual.make
			create btn_borrar.make
			create lista_botones.make (10)
			create lista_btns_operaciones.make (4)

			set_text ("CALCU_EIFFEL")
			-- Titulo del window
			l_size.make (5, 13)
			set_auto_scale_base_size (l_size)
			l_size.make (250, 230)
			set_client_size (l_size)

			--ETIQUETA DE OPERACION	
			l_point.make (8, 10)
			lbl_formula.set_location (l_point)
			lbl_formula.set_text ("OPERACIÓN:")
			l_size.make (155, 20)
			lbl_formula.set_size (l_size)

			--TEXTBOX DE OPERACION
			l_point.make (8, 28)
			txt_formula.set_location (l_point)
			txt_formula.set_tab_index (0)
			l_size.make (150, 25)
			txt_formula.set_size (l_size)
			txt_formula.set_read_only (True)

			-- BOTON DE LIMPIAR TEXTBOX
			l_point.make (165, 28)
			btn_borrar.set_location (l_point)
			l_size.make (80, 25)
			btn_borrar.set_size (l_size)
			btn_borrar.set_text ("BORRAR")
			btn_borrar.add_click (create {EVENT_HANDLER}.make (Current, $limpiar_operacion))

			--BOTON NUMERO 0
			lista_botones.put (0, create {WINFORMS_BUTTON}.make)
			l_point.make (8, 180)
			lista_botones.item (0).set_location (l_point)
			lista_botones.item (0).set_text ("0")

			--BOTON NUMERO 1
			lista_botones.put (1, create {WINFORMS_BUTTON}.make)
			l_point.make (8, 60)
			lista_botones.item (1).set_location (l_point)
			lista_botones.item (1).set_text ("1")

			--BOTON NUMERO 2
			lista_botones.put (2, create {WINFORMS_BUTTON}.make)
			l_point.make (48, 60)
			lista_botones.item (2).set_location (l_point)
			lista_botones.item (2).set_text ("2")

			--BOTON NUMERO 3
			lista_botones.put (3, create {WINFORMS_BUTTON}.make)
			l_point.make (88, 60)
			lista_botones.item (3).set_location (l_point)
			lista_botones.item (3).set_text ("3")

			--BOTON NUMERO 4
			lista_botones.put (4, create {WINFORMS_BUTTON}.make)
			l_point.make (8, 100)
			lista_botones.item (4).set_location (l_point)
			lista_botones.item (4).set_text ("4")

			--BOTON NUMERO 5
			lista_botones.put (5, create {WINFORMS_BUTTON}.make)
			l_point.make (48, 100)
			lista_botones.item (5).set_location (l_point)
			lista_botones.item (5).set_text ("5")

			--BOTON NUMERO 6
			lista_botones.put (6, create {WINFORMS_BUTTON}.make)
			l_point.make (88, 100)
			lista_botones.item (6).set_location (l_point)
			lista_botones.item (6).set_text ("6")


			--BOTON NUMERO 7
			lista_botones.put (7, create {WINFORMS_BUTTON}.make)
			l_point.make (8, 140)
			lista_botones.item (7).set_location (l_point)
			lista_botones.item (7).set_text ("7")

			--BOTON NUMERO 8
			lista_botones.put (8, create {WINFORMS_BUTTON}.make)
			l_point.make (48, 140)
			lista_botones.item (8).set_location (l_point)
			lista_botones.item (8).set_text ("8")

			--BOTON NUMERO 9
			lista_botones.put (9, create {WINFORMS_BUTTON}.make)
			l_point.make (88, 140)
			lista_botones.item (9).set_location (l_point)
			lista_botones.item (9).set_text ("9")

			from
				i := 0
			until
				i = 10
			loop
				l_size.make (30, 30)
				lista_botones.item (i).set_size (l_size)
				lista_botones.item (i).add_click (create {EVENT_HANDLER}.make (Current, $agregar_numero_a_text_box))
				i := i + 1
			end

			--BOTON OPERACION +
			lista_btns_operaciones.put (0, create {WINFORMS_BUTTON}.make)
			l_point.make (128, 60)
			lista_btns_operaciones.item (0).set_location (l_point)
			lista_btns_operaciones.item (0).set_text ("+")

			--BOTON OPERACION -
			lista_btns_operaciones.put (1, create {WINFORMS_BUTTON}.make)
			l_point.make (128, 100)
			lista_btns_operaciones.item (1).set_location (l_point)
			lista_btns_operaciones.item (1).set_text ("-")

			--BOTON OPERACION *
			lista_btns_operaciones.put (2, create {WINFORMS_BUTTON}.make)
			l_point.make (128, 140)
			lista_btns_operaciones.item (2).set_location (l_point)
			lista_btns_operaciones.item (2).set_text ("*")

			--BOTON OPERACION /
			lista_btns_operaciones.put (3, create {WINFORMS_BUTTON}.make)
			l_point.make (128, 180)
			lista_btns_operaciones.item (3).set_location (l_point)
			lista_btns_operaciones.item (3).set_text ("/")

			from
				i := 0
			until
				i = 4
			loop
				l_size.make (30, 30)
				lista_btns_operaciones.item (i).set_size (l_size)
				lista_btns_operaciones.item (i).add_click (create {EVENT_HANDLER}.make (Current, $agregar_simbolo_operacion))
				i := i + 1
			end

			--BOTON CALCULAR OPERACION =
			l_point.make (48, 180)
			btn_igual.set_location (l_point)
			l_size.make (70, 30)
			btn_igual.set_size (l_size)
			btn_igual.set_tab_index (1)
			btn_igual.set_text ("=")
			btn_igual.add_click (create {EVENT_HANDLER}.make (Current, $realizar_operacion))

			controls.add (txt_formula)
			controls.add (lbl_formula)
			controls.add (btn_igual)
			controls.add (btn_borrar)

			from
				i := 0
			until
				i = 10
			loop
				controls.add (lista_botones.item (i))
				i := i + 1
			end

			from
				i := 0
			until
				i = 4
			loop
				controls.add (lista_btns_operaciones.item (i))
				i := i + 1
			end
		end

feature -- IMPLEMENTACION

	dispose_boolean (a_disposing: BOOLEAN)
			-- METODO LLAMADO CUANDO EL FORM DEBE CERRARSE.
		local
			retried: BOOLEAN
		do
			if not retried then
				if components /= Void then
					components.dispose
				end
			end
			Precursor {WINFORMS_FORM}(a_disposing)
		rescue
			retried := true
			retry
		end

	limpiar_operacion (sender: SYSTEM_OBJECT args: EVENT_ARGS)
			-- Feature realizado cuando el boton limpiar es clickeado.
		do
			 txt_formula.set_text ("")
		end

	agregar_numero_a_text_box (sender: SYSTEM_OBJECT args: EVENT_ARGS)
			-- Feature realizado cuando un boton es presionado.
		local
			btn: WINFORMS_BUTTON
			l_text: STRING
		do
			btn ?= sender
			check
				non_void_btn: btn /= Void
			end
			l_text := txt_formula.text
			l_text.append (create {STRING}.make_from_cil (btn.text))
			txt_formula.set_text (l_text)
		end

	agregar_simbolo_operacion (sender: SYSTEM_OBJECT args: EVENT_ARGS)
			-- Feature efectuada cuando el boton de operacion es presionado.
		local
			btn: WINFORMS_BUTTON
			l_text: STRING
		do
			btn ?= sender
			check
				non_void_btn: btn /= Void
			end
			l_text := txt_formula.text
			l_text.append (" ")
			l_text.append (create {STRING}.make_from_cil (btn.text))
			l_text.append (" ")
			txt_formula.set_text (l_text)
		end

	realizar_operacion (sender: SYSTEM_OBJECT args: EVENT_ARGS)
			-- Feature efectuada cuando el boton igual es presionado.
		local
			my_parse: PARSER_PARSER
			retried: BOOLEAN
			res: WINFORMS_DIALOG_RESULT
			l_args: PARSER_ARGUMENTS
			l_int_math: INTEGER_MATH
		do
			if not retried then
				if not txt_formula.text.equals ({SYSTEM_STRING}.empty) then
						-- parse the formula and get the arguments
					create my_parse.make
					l_args := my_parse.parse (txt_formula.text)
					create l_int_math.make
					txt_formula.set_text (l_int_math.get_result (
						{SYSTEM_CONVERT}.to_int_32 (l_args.arg_1),
						l_args.op, {SYSTEM_CONVERT}.to_int_32 (l_args.arg_2)))
				end
				if txt_formula.text.equals ({SYSTEM_STRING}.empty) then
					res := {WINFORMS_MESSAGE_BOX}.show (
					"POR FAVOR INGRESE DATOS %N%N")

				end
			else
				res := {WINFORMS_MESSAGE_BOX}.show (
					"POR FAVOR INGRESE DATOS %N%N")

			end
		rescue
			retried := True
			retry
		end



end -- Class CALCU_EIFFEL


