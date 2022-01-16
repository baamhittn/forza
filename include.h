typedef struct  s_forza{
	int32_t IsRaceOn; // = 1 when race is on. = 0 when in menus/race stopped …
	uint32_t TimestampMS; //Can overflow to 0 eventually
	float EngineMaxRpm;
	float EngineIdleRpm;
	float CurrentEngineRpm;
	float AccelerationX; //In the car's local space; X = right, Y = up, Z = forward
	float AccelerationY;
	float AccelerationZ;
	float VelocityX; //In the car's local space; X = right, Y = up, Z = forward
	float VelocityY;
	float VelocityZ;
	float AngularVelocityX; //In the car's local space; X = pitch, Y = yaw, Z = roll
	float AngularVelocityY;
	float AngularVelocityZ;
	float Yaw;
	float Pitch;
	float Roll;
	float NormalizedSuspensionTravelFrontLeft; // Suspension travel normalized: 0.0f = max stretch; 1.0 = max compression
	float NormalizedSuspensionTravelFrontRight;
	float NormalizedSuspensionTravelRearLeft;
	float NormalizedSuspensionTravelRearRight;
	float TireSlipRatioFrontLeft; // Tire normalized slip ratio, = 0 means 100% grip and |ratio| > 1.0 means loss of grip.
	float TireSlipRatioFrontRight;
	float TireSlipRatioRearLeft;
	float TireSlipRatioRearRight;
	float WheelRotationSpeedFrontLeft; // Wheel rotation speed radians/sec.
	float WheelRotationSpeedFrontRight;
	float WheelRotationSpeedRearLeft;
	float WheelRotationSpeedRearRight;
	int32_t WheelOnRumbleStripFrontLeft; // = 1 when wheel is on rumble strip, = 0 when off.
	int32_t WheelOnRumbleStripFrontRight;
	int32_t WheelOnRumbleStripRearLeft;
	int32_t WheelOnRumbleStripRearRight;
	float WheelInPuddleDepthFrontLeft; // = from 0 to 1, where 1 is the deepest puddle
	float WheelInPuddleDepthFrontRight;
	float WheelInPuddleDepthRearLeft;
	float WheelInPuddleDepthRearRight;
	float SurfaceRumbleFrontLeft; // Non-dimensional surface rumble values passed to controller force feedback
	float SurfaceRumbleFrontRight;
	float SurfaceRumbleRearLeft;
	float SurfaceRumbleRearRight;
	float TireSlipAngleFrontLeft; // Tire normalized slip angle, = 0 means 100% grip and |angle| > 1.0 means loss of grip.
	float TireSlipAngleFrontRight;
	float TireSlipAngleRearLeft;
	float TireSlipAngleRearRight;
	float TireCombinedSlipFrontLeft; // Tire normalized combined slip, = 0 means 100% grip and |slip| > 1.0 means loss of grip.
	float TireCombinedSlipFrontRight;
	float TireCombinedSlipRearLeft;
	float TireCombinedSlipRearRight;
	float SuspensionTravelMetersFrontLeft; // Actual suspension travel in meters
	float SuspensionTravelMetersFrontRight;
	float SuspensionTravelMetersRearLeft;
	float SuspensionTravelMetersRearRight;
	int32_t CarOrdinal; //Unique ID of the car make/model
	int32_t CarClass; //Between 0 (D -- worst cars) and 7 (X class -- best cars) inclusive
	int32_t CarPerformanceIndex; //Between 100 (slowest car) and 999 (fastest car) inclusive
	int32_t DrivetrainType; //Corresponds to EDrivetrainType; 0 = FWD, 1 = RWD, 2 = AWD
	int32_t NumCylinders; //Number of cylinders in the engine
 	int32_t HorizonPlaceholder1;// unknown FH4 values
	int32_t HorizonPlaceholder2;// unknown FH4 values
	int32_t HorizonPlaceholder3;// unknown FH4 values
	float PositionX;
	float PositionY;
	float PositionZ;
	float Speed; // meters per second
	float Power; // watts
	float Torque; // newton meter
	float TireTempFrontLeft;
	float TireTempFrontRight;
	float TireTempRearLeft;
	float TireTempRearRight;
	float Boost;
	float Fuel;
	float DistanceTraveled;
	float BestLap;
	float LastLap;
	float CurrentLap;
	float CurrentRaceTime;
	uint16_t LapNumber;
	uint8_t RacePosition;
	uint8_t Accel;
	uint8_t Brake;
	uint8_t Clutch;
	uint8_t HandBrake;
	uint8_t Gear;
	int8_t Steer;
	int8_t NormalizedDrivingLine;
	int8_t NormalizedAIBrakeDifference;
} forza_struct ;


typedef union u_forza {
	forza_struct output;
	uint8_t input[sizeof(forza_struct)];
}forza_union;
