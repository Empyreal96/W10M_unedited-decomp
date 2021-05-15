// CmpBuildVirtualReplicationStack 
 
int __fastcall CmpBuildVirtualReplicationStack(int a1, int *a2, unsigned int *a3, unsigned int *a4)
{
  int v4; // r6
  unsigned int v5; // r4
  int result; // r0
  _BYTE *v10; // r0
  unsigned int v11; // r4
  _WORD *v12; // r1
  unsigned int v13; // r2
  int v14; // r0
  int v15; // r0
  _WORD *v16; // r1
  unsigned int v17; // r5
  unsigned int v18; // r1
  unsigned int v19; // r1
  unsigned int v20; // r2
  int v21[10]; // [sp+0h] [bp-28h] BYREF

  v21[0] = (int)a2;
  v21[1] = (int)a3;
  v21[2] = (int)a4;
  v4 = a1;
  v5 = *(_DWORD *)(a1 + 4);
  *a4 = 0;
  result = RtlULongLongToULong(28 * ((v5 >> 21) & 0x3FF), (28 * (unsigned __int64)((v5 >> 21) & 0x3FF)) >> 32, v21);
  if ( result >= 0 )
  {
    v10 = (_BYTE *)ExAllocatePoolWithTag(1, v21[0], 538987843);
    v11 = (unsigned int)v10;
    if ( v10 )
    {
      memset(v10, 0, v21[0]);
      v12 = (_WORD *)a2[1];
      v13 = 4;
      v21[0] = *a2;
      LOWORD(v14) = v21[0];
      while ( *v12 != 92 || --v13 )
      {
        v14 = (unsigned __int16)(v14 - 2);
        if ( !v14 )
          goto LABEL_24;
        ++v12;
      }
      v15 = (unsigned __int16)(v14 - 2);
      v16 = v12 + 1;
      if ( v15 )
      {
        v17 = v11;
        do
        {
          *(_DWORD *)(v17 + 4) = v16;
          while ( v15 && *v16 != 92 )
          {
            *(_WORD *)v17 += 2;
            v15 = (unsigned __int16)(v15 - 2);
            ++v16;
          }
          ++v13;
          *(_WORD *)(v17 + 2) = *(_WORD *)v17;
          v17 += 28;
          if ( !v15 )
            break;
          do
          {
            if ( *v16 != 92 )
              break;
            v15 = (unsigned __int16)(v15 - 2);
            ++v16;
          }
          while ( v15 );
        }
        while ( v15 );
      }
      *a3 = v13;
      if ( v13 <= 1 )
      {
LABEL_23:
        *(_DWORD *)(v11 + 24) = 0;
        HvpGetCellContextReinitialize((_DWORD *)(v11 + 12));
        *a4 = v11;
        return 0;
      }
      v18 = v11 + 28 * v13;
      while ( v4 )
      {
        v19 = v18 - 28;
        *(_DWORD *)(v19 + 24) = *(_DWORD *)(v4 + 24) >> 31;
        HvpGetCellContextReinitialize((_DWORD *)(v19 + 12));
        v4 = *(_DWORD *)(v4 + 40);
        if ( v20 <= 1 )
          goto LABEL_23;
      }
LABEL_24:
      ExFreePoolWithTag(v11);
      result = -1073741811;
    }
    else
    {
      result = -1073741670;
    }
  }
  return result;
}
