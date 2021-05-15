// PiPnpRtlGatherDeviceDeleteInfo 
 
int __fastcall PiPnpRtlGatherDeviceDeleteInfo(unsigned __int16 *a1, unsigned int *a2)
{
  _BYTE *v4; // r0
  int v5; // r5
  unsigned int v7; // [sp+10h] [bp-28h] BYREF
  int v8; // [sp+14h] [bp-24h] BYREF
  int v9; // [sp+18h] [bp-20h] BYREF
  int v10; // [sp+1Ch] [bp-1Ch] BYREF
  int v11[6]; // [sp+20h] [bp-18h] BYREF

  v4 = (_BYTE *)ExAllocatePoolWithTag(1, 84, 1198550608);
  *a2 = (unsigned int)v4;
  if ( v4 )
  {
    memset(v4, 0, 84);
    RtlInitUnicodeString((unsigned int)v11, a1);
    if ( PlugPlayGetDeviceStatus(v11, &v10, (_DWORD *)*a2, &v9, 0) < 0 )
      *(_DWORD *)*a2 = 45;
    v7 = 78;
    v5 = CmGetDeviceRegProp(PiPnpRtlCtx, (int)a1, 0, 9, (int)&v8, *a2 + 4, (int)&v7);
    if ( v5 >= 0 && v8 == 1 && v7 > 2 )
    {
      *(_WORD *)(*a2 + 80) = 0;
    }
    else
    {
      v5 = 0;
      *(_WORD *)(*a2 + 4) = 0;
    }
  }
  else
  {
    v5 = -1073741670;
    if ( *a2 )
      ExFreePoolWithTag(*a2);
    *a2 = 0;
  }
  return v5;
}
