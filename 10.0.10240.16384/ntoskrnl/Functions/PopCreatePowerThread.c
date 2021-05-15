// PopCreatePowerThread 
 
int __fastcall PopCreatePowerThread(int a1, int a2)
{
  int result; // r0
  int v3; // r4
  int v4; // [sp+10h] [bp-28h] BYREF
  int v5; // [sp+14h] [bp-24h] BYREF
  int v6[8]; // [sp+18h] [bp-20h] BYREF

  v6[0] = 24;
  v6[1] = 0;
  v6[3] = 512;
  v6[2] = 0;
  v6[4] = 0;
  v6[5] = 0;
  result = PsCreateSystemThread(&v4, 0x1FFFFF, v6, 0, 0, a1, a2);
  if ( result >= 0 )
  {
    v3 = ObReferenceObjectByHandle(v4, 0x1FFFFF, PsThreadType, 0, &v5, 0);
    ZwClose();
    if ( v3 >= 0 )
    {
      KeSetActualBasePriorityThread(v5, 13);
      ObfDereferenceObjectWithTag(v5, 1953261124);
    }
    result = 0;
  }
  return result;
}
