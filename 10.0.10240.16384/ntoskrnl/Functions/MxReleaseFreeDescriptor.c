// MxReleaseFreeDescriptor 
 
int __fastcall MxReleaseFreeDescriptor(int result, int a2)
{
  unsigned int *v2; // r4
  int v3; // r5
  __int64 v4; // r2
  __int64 v5; // r2
  int v6; // r3
  __int64 v7; // r2
  _DWORD v8[3]; // [sp+0h] [bp-20h] BYREF
  __int64 v9; // [sp+Ch] [bp-14h]

  v2 = (unsigned int *)result;
  v4 = *(_QWORD *)result;
  v3 = 0;
  v8[2] = a2;
  v9 = v4;
  HIDWORD(v4) = *(_DWORD *)(result + 12);
  if ( HIDWORD(v4) != -1 )
  {
    HIDWORD(v9) = HIDWORD(v4) - v4 + 1024;
    result = MxCreateFreePfns(v8);
    v3 = 1;
  }
  HIDWORD(v5) = v2[2];
  if ( HIDWORD(v5) != -1 )
  {
    LODWORD(v5) = HIDWORD(v5) & 0xFFFFFC00;
    if ( (HIDWORD(v5) & 0xFFFFFC00) > *v2 )
    {
      HIDWORD(v5) = HIDWORD(v5) - v5 + 1;
      v9 = v5;
      result = MxCreateFreePfns(v8);
      if ( !v3 )
      {
        v6 = *v2 & 0x3FF;
        if ( v6 )
        {
          HIDWORD(v7) = 1024 - v6;
          LODWORD(v7) = *v2;
          v9 = v7;
          result = MxCreateFreePfns(v8);
        }
      }
    }
    else
    {
      result = sub_96AE0C(result);
    }
  }
  return result;
}
