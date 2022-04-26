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
  srcs = ["test/StateChooserTest.cpp", "robotcar/StateChooser.cpp", "robotcar/StateChooser.h", "robotcar/State.h", "robotcar/StateNamer.h", "robotcar/StateNamer.cpp"],
  deps = ["@com_google_googletest//:gtest_main"],
)

cc_test(
  name = "exp",
  size = "small",
  srcs = ["test/test.cpp", "robotcar/Pinger.h", "test/PingerMock.h", "test/PingerMock.cpp"],
)
