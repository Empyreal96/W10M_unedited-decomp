// NtApphelpCacheControl 
 
int __fastcall NtApphelpCacheControl(int a1, int a2)
{
  int v5; // r4
  int v6; // r4
  unsigned int v7; // r3
  unsigned int v8; // r1
  int v9; // [sp+18h] [bp-40h] BYREF
  unsigned int v10; // [sp+1Ch] [bp-3Ch] BYREF
  char v11[8]; // [sp+20h] [bp-38h] BYREF
  char v12[40]; // [sp+30h] [bp-28h] BYREF

  if ( a1 >= 10 )
    return -1073741811;
  v9 = 0;
  v10 = 0;
  if ( a1 == 9 )
    return sub_7D5A4C();
  switch ( a1 )
  {
    case 0:
    case 6:
      v5 = -1073741275;
      break;
    case 1:
    case 2:
    case 3:
    case 7:
      v5 = 0;
      break;
    case 4:
    case 5:
    case 8:
      v5 = -1073741823;
      break;
    default:
      return -1073741811;
  }
  if ( !g_AhcDeviceObject )
  {
    if ( RtlInitUnicodeStringEx((int)v11, L"\\Device\\ahcache") < 0
      || IoGetDeviceObjectPointer(v11, -1073741824, &v9, &v10) < 0 )
    {
      return v5;
    }
    __dmb(0xBu);
    v7 = v10;
    do
      v8 = __ldrex((unsigned int *)&g_AhcDeviceObject);
    while ( !v8 && __strex(v7, (unsigned int *)&g_AhcDeviceObject) );
    __dmb(0xBu);
    if ( v8 )
      ObfDereferenceObject(v9);
    else
      g_AhcFileObject = v9;
  }
  KeInitializeEvent((int)v12, 1, 0);
  v6 = IoBuildDeviceIoControlRequest((4 * a1) | 0x220003, g_AhcDeviceObject, a2, 184, 0, 0);
  if ( !v6 )
    return -1073741823;
  *(_BYTE *)(v6 + 32) = ExGetPreviousMode();
  return IofCallDriver(g_AhcDeviceObject, v6);
}
