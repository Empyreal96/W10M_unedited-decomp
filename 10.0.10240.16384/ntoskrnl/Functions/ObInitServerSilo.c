// ObInitServerSilo 
 
int ObInitServerSilo()
{
  int result; // r0
  int v1; // [sp+Ch] [bp-3Ch] BYREF
  __int16 v2; // [sp+10h] [bp-38h]
  __int16 v3; // [sp+12h] [bp-36h]
  const __int16 *v4; // [sp+14h] [bp-34h]

  v2 = 16;
  v3 = 18;
  v4 = L"Global??";
  result = PsAllocateMonitorContextServerSilo(ObSiloMonitor, 116, &v1);
  if ( result >= 0 )
    result = sub_810CEC();
  return result;
}
