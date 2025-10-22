add_executable(sos_app
    main.cpp
    MainWindow.cpp
    Board.cpp
    GameController.cpp
)

target_link_libraries(sos_app Qt6::Widgets)
