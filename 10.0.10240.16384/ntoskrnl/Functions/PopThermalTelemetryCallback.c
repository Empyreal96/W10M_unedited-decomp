// PopThermalTelemetryCallback 
 
int PopThermalTelemetryCallback()
{
  return PopQueueWorkItem(&PopThermalTelemetryTimer[22]);
}
