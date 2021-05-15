// ExpCovReadRequestBuffer 
 
int __fastcall ExpCovReadRequestBuffer(_DWORD *a1, int a2, _DWORD *a3, _DWORD *a4)
{
  int v5; // r4
  int v6; // r5
  unsigned int v7; // r5
  unsigned int v8; // r6
  _BYTE *v9; // r0
  unsigned int v10; // r8
  int v12; // [sp+8h] [bp-20h] BYREF
  _BYTE *v13; // [sp+Ch] [bp-1Ch]
  _DWORD *varg_r0; // [sp+30h] [bp+8h]
  int varg_r1; // [sp+34h] [bp+Ch]
  _DWORD *varg_r2; // [sp+38h] [bp+10h]
  _DWORD *varg_r3; // [sp+3Ch] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  v12 = (int)a3;
  v13 = a4;
  varg_r1 = a2;
  v5 = 0;
  v6 = *a1;
  *a4 = *a1;
  if ( v6 )
  {
    if ( v6 == 1 )
    {
      *a3 = a1[1];
      a3[1] = a1[2];
      a3[2] = a1[3];
      a3[3] = a1[4];
    }
    else if ( v6 == 2 && (v12 = a1[1], v7 = a1[2], v8 = (unsigned __int16)v12, (_WORD)v12) && (v12 & 1) == 0 )
    {
      if ( (v7 & 1) != 0 )
        ExRaiseDatatypeMisalignment();
      if ( (unsigned __int16)v12 + v7 > MmUserProbeAddress || (unsigned __int16)v12 + v7 < v7 )
        *(_BYTE *)MmUserProbeAddress = 0;
      v9 = (_BYTE *)ExAllocatePoolWithTag(1, v8, 1920364355);
      v10 = (unsigned int)v9;
      v13 = v9;
      if ( v9 )
      {
        memset(v9, 0, v8);
        memmove(v10, v7, v8);
        v5 = RtlDuplicateUnicodeString(1, (int)&v12, a2);
        ExFreePoolWithTag(v10);
      }
      else
      {
        v5 = -1073741670;
      }
    }
    else
    {
      v5 = -1073741811;
    }
  }
  return v5;
}
