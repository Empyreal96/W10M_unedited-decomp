// WheapApplyThresholdChecks 
 
int __fastcall WheapApplyThresholdChecks(__int64 a1, int a2, int a3)
{
  _DWORD *v3; // r5
  unsigned int v4; // r9
  int v6; // r6
  int v7; // r8
  int v8; // r7
  unsigned __int64 v9; // r0
  unsigned int v10; // r3
  __int64 v11; // [sp+0h] [bp-28h] BYREF
  int v12; // [sp+8h] [bp-20h]
  int v13; // [sp+Ch] [bp-1Ch]

  v11 = a1;
  v12 = a2;
  v13 = a3;
  v3 = (_DWORD *)a1;
  ++*(_DWORD *)(a1 + 68);
  WheapGetErrorThresholdInformation();
  v4 = v11;
  if ( (unsigned int)v11 <= 1 )
    return 1;
  KeQueryTickCount((int *)&v11);
  v6 = HIDWORD(v11);
  v7 = v12;
  v8 = v11;
  if ( v12
    && (LODWORD(v9) = _rt_sdiv64(
                        (unsigned int)dword_989680,
                        (v11 - *((_QWORD *)v3 + 7)) * (unsigned int)KeMaximumIncrement),
        v9 > (unsigned int)v7) )
  {
    v3[15] = v6;
    v3[16] = 1;
    v3[14] = v8;
  }
  else
  {
    v10 = v3[16] + 1;
    v3[16] = v10;
    if ( v10 >= v4 )
    {
      v3[15] = v6;
      v3[16] = 0;
      v3[14] = v8;
      return 1;
    }
  }
  return 0;
}
