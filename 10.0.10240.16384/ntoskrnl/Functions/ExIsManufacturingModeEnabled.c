// ExIsManufacturingModeEnabled 
 
BOOL ExIsManufacturingModeEnabled()
{
  return (ExpManufacturingInformation & 1) != 0;
}
