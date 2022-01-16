#include "WiFi.h"
#include "AsyncUDP.h"
#include "include.h"


const char * ssid = "airport";
const char * password = "f2da1cf58dc09633edb4c83742877a88d215130190ae2277f49ea99b24";

#define DAC1 25

forza_union forza_data;

AsyncUDP udp;

void setup()
{


  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("WiFi Failed");
    while (1) {
      delay(1000);
    }
  }
  if (udp.listen(55555)) {
    Serial.print("UDP Listening on IP: ");
    Serial.println(WiFi.localIP());
    udp.onPacket([](AsyncUDPPacket packet) {
      for (int x = 0; x < packet.length(); x++) {
        forza_data.input[x] = packet.data()[x];
      }
      printf("Speed: %f Gear: %d CurrentEngineRpm: %f Brake: %d AccelerationX: %f\n", forza_data.output.Speed * 3.6, forza_data.output.Gear, forza_data.output.CurrentEngineRpm, forza_data.output.Brake, forza_data.output.AccelerationX); // meters per second
      //      printf("IsRaceOn: %d\n", forza_data.output.IsRaceOn); // = 1 when race is on. = 0 when in menus/race stopped …
      //      printf("TimestampMS: %d\n", forza_data.output.TimestampMS); //Can overflow to 0 eventually
      //      printf("EngineMaxRpm: %f\n", forza_data.output.EngineMaxRpm);
      //      printf("EngineIdleRpm: %f\n", forza_data.output.EngineIdleRpm);
      //      printf("CurrentEngineRpm: %f\n", forza_data.output.CurrentEngineRpm);
      //      printf("AccelerationX: %f\n", forza_data.output.AccelerationX); //In the car's local space: %f\n",forza_data.output.); X = right, Y = up, Z = forward
      //      printf("AccelerationY: %f\n", forza_data.output.AccelerationY);
      //      printf("AccelerationZ: %f\n", forza_data.output.AccelerationZ);
      //      printf("VelocityX: %f\n", forza_data.output.VelocityX); //In the car's local space: %f\n",forza_data.output.); X = right, Y = up, Z = forward
      //      printf("VelocityY: %f\n", forza_data.output.VelocityY);
      //      printf("VelocityZ: %f\n", forza_data.output.VelocityZ);
      //      printf("AngularVelocityX: %f\n", forza_data.output.AngularVelocityX); //In the car's local space: %f\n",forza_data.output.); X = pitch, Y = yaw, Z = roll
      //      printf("AngularVelocityY: %f\n", forza_data.output.AngularVelocityY);
      //      printf("AngularVelocityZ: %f\n", forza_data.output.AngularVelocityZ);
      //      printf("Yaw: %f\n", forza_data.output.Yaw);
      //      printf("Pitch: %f\n", forza_data.output.Pitch);
      //      printf("Roll: %f\n", forza_data.output.Roll);
      //      printf("NormalizedSuspensionTravelFrontLeft: %f\n", forza_data.output.NormalizedSuspensionTravelFrontLeft); // Suspension travel normalized: 0.0f = max stretch: %f\n",forza_data.output.); 1.0 = max compression
      //      printf("NormalizedSuspensionTravelFrontRight: %f\n", forza_data.output.NormalizedSuspensionTravelFrontRight);
      //      printf("NormalizedSuspensionTravelRearLeft: %f\n", forza_data.output.NormalizedSuspensionTravelRearLeft);
      //      printf("NormalizedSuspensionTravelRearRight: %f\n", forza_data.output.NormalizedSuspensionTravelRearRight);
      //      printf("TireSlipRatioFrontLeft: %f\n", forza_data.output.TireCombinedSlipFrontLeft); // Tire normalized slip ratio, = 0 means 100%f grip and |ratio| > 1.0 means loss of grip.
      //      printf("TireSlipRatioFrontRight: %f\n", forza_data.output.TireSlipRatioFrontRight);
      //      printf("TireSlipRatioRearLeft: %f\n", forza_data.output.TireSlipAngleRearLeft);
      //      printf("TireSlipRatioRearRight: %f\n", forza_data.output.TireSlipAngleRearRight);
      //      printf("WheelRotationSpeedFrontLeft: %f\n", forza_data.output.WheelRotationSpeedFrontLeft); // Wheel rotation speed radians/sec.
      //      printf("WheelRotationSpeedFrontRight: %f\n", forza_data.output.WheelRotationSpeedFrontRight);
      //      printf("WheelRotationSpeedRearLeft: %f\n", forza_data.output.WheelRotationSpeedRearLeft);
      //      printf("WheelRotationSpeedRearRight: %f\n", forza_data.output.WheelRotationSpeedRearRight);
      //      printf("WheelOnRumbleStripFrontLeft: %d\n", forza_data.output.WheelOnRumbleStripFrontLeft); // = 1 when wheel is on rumble strip, = 0 when off.
      //      printf("WheelOnRumbleStripFrontRight: %d\n", forza_data.output.WheelOnRumbleStripFrontRight);
      //      printf("WheelOnRumbleStripRearLeft: %d\n", forza_data.output.WheelOnRumbleStripRearLeft);
      //      printf("WheelOnRumbleStripRearRight: %d\n", forza_data.output.WheelOnRumbleStripRearRight);
      //      printf("WheelInPuddleDepthFrontLeft: %f\n", forza_data.output.WheelInPuddleDepthFrontLeft); // = from 0 to 1, where 1 is the deepest puddle
      //      printf("WheelInPuddleDepthFrontRight: %f\n", forza_data.output.WheelInPuddleDepthFrontRight);
      //      printf("WheelInPuddleDepthRearLeft: %f\n", forza_data.output.WheelInPuddleDepthRearLeft);
      //      printf("WheelInPuddleDepthRearRight: %f\n", forza_data.output.WheelInPuddleDepthRearRight);
      //      printf("SurfaceRumbleFrontLeft: %f\n", forza_data.output.SurfaceRumbleFrontLeft); // Non-dimensional surface rumble values passed to controller force feedback
      //      printf("SurfaceRumbleFrontRight: %f\n", forza_data.output.SurfaceRumbleFrontRight);
      //      printf("SurfaceRumbleRearLeft: %f\n", forza_data.output.SurfaceRumbleRearLeft);
      //      printf("SurfaceRumbleRearRight: %f\n", forza_data.output.SurfaceRumbleRearRight);
      //      printf("TireSlipAngleFrontLeft: %f\n", forza_data.output.TireSlipAngleFrontLeft); // Tire normalized slip angle, = 0 means 100%f grip and |angle| > 1.0 means loss of grip.
      //      printf("TireSlipAngleFrontRight: %f\n", forza_data.output.TireSlipAngleFrontRight);
      //      printf("TireSlipAngleRearLeft: %f\n", forza_data.output.TireSlipAngleRearLeft);
      //      printf("TireSlipAngleRearRight: %f\n", forza_data.output.TireSlipAngleRearRight);
      //      printf("TireCombinedSlipFrontLeft: %f\n", forza_data.output.TireCombinedSlipFrontLeft); // Tire normalized combined slip, = 0 means 100%f grip and |slip| > 1.0 means loss of grip.
      //      printf("TireCombinedSlipFrontRight: %f\n", forza_data.output.TireCombinedSlipFrontRight);
      //      printf("TireCombinedSlipRearLeft: %f\n", forza_data.output.TireCombinedSlipRearLeft);
      //      printf("TireCombinedSlipRearRight: %f\n", forza_data.output.TireCombinedSlipRearRight);
      //      printf("SuspensionTravelMetersFrontLeft: %f\n", forza_data.output.SuspensionTravelMetersFrontLeft); // Actual suspension travel in meters
      //      printf("SuspensionTravelMetersFrontRight: %f\n", forza_data.output.SuspensionTravelMetersFrontRight);
      //      printf("SuspensionTravelMetersRearLeft: %f\n", forza_data.output.SuspensionTravelMetersRearLeft);
      //      printf("SuspensionTravelMetersRearRight: %f\n", forza_data.output.SuspensionTravelMetersRearRight);
      //      printf("CarOrdinal: %d\n", forza_data.output.CarOrdinal); //Unique ID of the car make/model
      //      printf("CarClass: %d\n", forza_data.output.CarClass); //Between 0 (D -- worst cars) and 7 (X class -- best cars) inclusive
      //      printf("CarPerformanceIndex: %d\n", forza_data.output.CarPerformanceIndex); //Between 100 (slowest car) and 999 (fastest car) inclusive
      //      printf("DrivetrainType: %d\n", forza_data.output.DrivetrainType); //Corresponds to EDrivetrainType: %f\n",forza_data.output.); 0 = FWD, 1 = RWD, 2 = AWD
      //      printf("NumCylinders: %d\n", forza_data.output.NumCylinders); //Number of cylinders in the engine
      //      printf("PositionX: %f\n", forza_data.output.PositionX);
      //      printf("PositionY: %f\n", forza_data.output.PositionY);
      //      printf("PositionZ: %f\n", forza_data.output.PositionZ);
      //      printf("Speed: %f\n", forza_data.output.Speed); // meters per second
      //      printf("Power: %f\n", forza_data.output.Power); // watts
      //      printf("Torque: %f\n", forza_data.output.Torque); // newton meter
      //      printf("TireTempFrontLeft: %f\n", forza_data.output.TireTempFrontLeft);
      //      printf("TireTempFrontRight: %f\n", forza_data.output.TireTempFrontRight);
      //      printf("TireTempRearLeft: %f\n", forza_data.output.TireTempRearLeft);
      //      printf("TireTempRearRight: %f\n", forza_data.output.TireTempRearRight);
      //      printf("Boost: %f\n", forza_data.output.Boost);
      //      printf("Fuel: %f\n", forza_data.output.Fuel);
      //      printf("DistanceTraveled: %f\n", forza_data.output.DistanceTraveled);
      //      printf("BestLap: %f\n", forza_data.output.BestLap);
      //      printf("LastLap: %f\n", forza_data.output.LastLap);
      //      printf("CurrentLap: %f\n", forza_data.output.CurrentLap);
      //      printf("CurrentRaceTime: %f\n", forza_data.output.CurrentRaceTime);
      //      printf("LapNumber: %d\n", forza_data.output.LapNumber);
      //      printf("RacePosition: %d\n", forza_data.output.RacePosition);
      //      printf("Accel: %d\n", forza_data.output.Accel);
      //      printf("Brake: %d\n", forza_data.output.Brake);
      //      printf("Clutch: %d\n", forza_data.output.Clutch);
      //      printf("HandBrake: %d\n", forza_data.output.HandBrake);
      //      printf("Gear: %d\n", forza_data.output.Gear);
      //      printf("Steer: %d\n", forza_data.output.Steer);
      //      printf("NormalizedDrivingLine: %d\n", forza_data.output.NormalizedDrivingLine);
      //      printf("NormalizedAIBrakeDifference: %d\n", forza_data.output.NormalizedAIBrakeDifference);
    });
  }
}

void loop()
{
  uint8_t speed_out;
  speed_out = map(forza_data.output.Speed, 0, 50, 0, 255);
  dacWrite(DAC1, speed_out);

}
