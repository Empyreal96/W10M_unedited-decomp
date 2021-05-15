// PiPnpRtlEnumeratorFilterCallback 
 
int __fastcall PiPnpRtlEnumeratorFilterCallback(int a1, unsigned __int16 *a2, int a3, int a4)
{
  int v5; // r5
  unsigned __int16 *v9; // r4
  int (__fastcall *v10)(int, unsigned __int16 *, int, _DWORD); // r4
  _DWORD v12[8]; // [sp+8h] [bp-20h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  v5 = 0;
  if ( *(_BYTE *)(a4 + 4) )
  {
    CmIsDevicePresent();
  }
  else
  {
    v9 = *(unsigned __int16 **)a4;
    if ( !*(_DWORD *)a4
      || *v9 < 2u
      || !**((_WORD **)v9 + 1)
      || RtlInitUnicodeStringEx((int)v12, a2) >= 0
      && RtlPrefixUnicodeString(*(unsigned __int16 **)a4, (unsigned __int16 *)v12, 1) )
    {
      v5 = 1;
      v10 = *(int (__fastcall **)(int, unsigned __int16 *, int, _DWORD))(a4 + 8);
      if ( v10 )
        v5 = v10(a1, a2, a3, *(_DWORD *)(a4 + 12));
    }
  }
  return v5;
}
