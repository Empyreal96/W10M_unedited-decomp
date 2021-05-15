// KeNumaInitialize 
 
int KeNumaInitialize()
{
  int result; // r0
  int v1; // [sp+0h] [bp-30h] BYREF
  __int16 v2; // [sp+8h] [bp-28h] BYREF
  int (*v3)(void); // [sp+Ch] [bp-24h]
  int (__fastcall *v4)(_DWORD, _DWORD); // [sp+14h] [bp-1Ch]
  int v5; // [sp+1Ch] [bp-14h]
  void *v6; // [sp+20h] [bp-10h]
  int (__fastcall *v7)(_DWORD, _DWORD, _DWORD); // [sp+24h] [bp-Ch]

  result = off_617B54(11, 32, &v2, &v1);
  if ( result >= 0 )
  {
    KeNumberNodes = v2;
    KiNumaQueryProcessorNode = v3;
    KiQueryNodeCapacity = v6;
    KiQueryNodeDistance = v7;
    PnpQueryProximityNode = v4;
    PnpQueryProximityId = v5;
  }
  return result;
}
