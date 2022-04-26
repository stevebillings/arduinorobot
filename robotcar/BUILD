cc_test(
  name = "bot",
  size = "small",
  srcs = ["test/ControllerTest.cpp", "robotcar/State.h", "robotcar/StateNamer.h", "robotcar/StateChooser.h", "robotcar/StateNamer.cpp", "robotcar/StateChooser.cpp",
		"robotcar/Controller.h", "robotcar/Controller.cpp", "robotcar/Drive.h", "test/DriveMock.h", "test/DriveMock.cpp", "robotcar/Pinger.h",
		"test/PingerMock.h", "test/PingerMock.cpp",
		"robotcar/Turret.h", "test/TurretMock.h", "test/TurretMock.cpp"
		],
  deps = ["@com_google_googletest//:gtest_main"],
)

cc_test(
  name = "statechoosertest",
  size = "small",
  srcs = ["StateChooserTest.cpp", "StateChooser.cpp", "StateChooser.h", "State.h", "StateNamer.h", "StateNamer.cpp"],
  deps = ["@com_google_googletest//:gtest_main"],
)
