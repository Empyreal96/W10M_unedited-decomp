// SeCaptureObjectTypeList 
 
int __fastcall SeCaptureObjectTypeList(unsigned int a1, unsigned int a2, char a3, int *a4)
{
  unsigned int v4; // r4
  int v6; // r5
  int v7; // r8
  int v8; // r3
  int v9; // r0
  unsigned int i; // r6
  unsigned __int16 *v11; // r3
  int v12; // lr
  _DWORD *v13; // r9
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r3
  int *v20; // [sp+Ch] [bp-48h]
  _DWORD v22[14]; // [sp+1Ch] [bp-38h] BYREF

  v4 = a2;
  v6 = 0;
  v7 = 0;
  *a4 = 0;
  if ( a3 != 1 )
    return -1073741822;
  if ( a2 )
  {
    if ( a1 && a2 < -MmSystemRangeStart / 0x2Cu )
    {
      v8 = 8 * a2;
      if ( 8 * a2 )
      {
        if ( (a1 & 3) != 0 )
          ExRaiseDatatypeMisalignment(&MmSystemRangeStart);
        if ( v8 + a1 > MmUserProbeAddress || v8 + a1 < a1 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      v9 = ExAllocatePoolWithTag(1, 44 * a2, 1951360339);
      v7 = v9;
      if ( v9 )
      {
        for ( i = 0; i < v4; ++i )
        {
          v11 = (unsigned __int16 *)(a1 + 8 * i);
          v12 = *v11;
          if ( (unsigned int)v12 > 4 )
            goto LABEL_27;
          v13 = (_DWORD *)(v7 + 44 * i);
          *v13 = (unsigned __int16)v12;
          v20 = (int *)*((_DWORD *)v11 + 1);
          if ( ((unsigned __int8)v20 & 3) != 0 )
            ExRaiseDatatypeMisalignment(v9);
          v9 = *v20;
          v14 = v20[1];
          v15 = v20[2];
          v16 = v20[3];
          v13[1] = *v20;
          v13[2] = v14;
          v13[3] = v15;
          v13[4] = v16;
          v13[6] = 0;
          v13[7] = 0;
          v13[8] = 0;
          v13[10] = 0;
          v6 = 0;
          if ( i )
          {
            if ( v12 > *((unsigned __int16 *)v13 - 22) + 1 || !v12 )
              goto LABEL_27;
            v17 = v22[v12 - 1];
          }
          else
          {
            if ( v12 )
              goto LABEL_27;
            v17 = -1;
          }
          v13[5] = v17;
          v22[v12] = i;
          v4 = a2;
        }
      }
      else
      {
        v6 = -1073741670;
      }
    }
    else
    {
LABEL_27:
      v6 = -1073741811;
    }
  }
  if ( v6 < 0 )
  {
    if ( v7 )
      ExFreePoolWithTag(v7, 0);
  }
  else
  {
    *a4 = v7;
  }
  return v6;
}
