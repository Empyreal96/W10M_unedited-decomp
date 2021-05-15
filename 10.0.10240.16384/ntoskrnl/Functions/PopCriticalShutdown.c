// PopCriticalShutdown 
 
int PopCriticalShutdown()
{
  int v1[4]; // [sp+8h] [bp-28h] BYREF
  int v2[6]; // [sp+18h] [bp-18h] BYREF

  if ( (PoDebug & 1) != 0 )
    DbgPrint("PopCriticalShutdown: type %x\n", 1);
  v1[2] = 0;
  v1[0] = 6;
  v1[1] = -1073741820;
  v2[2] = 0;
  v2[3] = 0;
  v2[0] = 1;
  v2[1] = 128;
  __dmb(0xBu);
  PopCriticalShutdownInProgress = 1;
  return PopExecutePowerAction(v2, 0, v1, 5, 1);
}
