// HvApplyLegacyLogFile 
 
int __fastcall HvApplyLegacyLogFile(int a1, int a2, unsigned int *a3, int a4)
{
  int v7; // r1
  int v8; // r10
  int v9; // r4
  int v10; // r3
  int v11; // r4
  int v12; // r3
  unsigned int *v13; // r6
  unsigned int v14; // r7
  unsigned int v16; // [sp+8h] [bp-58h] BYREF
  _DWORD *v17; // [sp+Ch] [bp-54h] BYREF
  unsigned int v18[2]; // [sp+10h] [bp-50h] BYREF
  unsigned int v19[18]; // [sp+18h] [bp-48h] BYREF

  memset(v19, 0, 40);
  v7 = *(_DWORD *)(a1 + 32);
  v16 = 0;
  v8 = *(_DWORD *)(v7 + 40) >> 12;
  v9 = HvpRecoverDataReadRoutine(a1, a3, 0x200u, v8 + 4, (unsigned int *)&v17);
  if ( v9 >= 0 )
  {
    if ( *v17 == 1414678852 )
    {
      v18[0] = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 40) >> 9;
      v18[1] = (unsigned int)(v17 + 1);
      v11 = RtlNumberOfSetBits(v18);
      if ( v11 )
      {
        HvpGenerateLogMetadata(v18, 0, &v16, v10);
        v13 = (unsigned int *)(*(int (__fastcall **)(unsigned int, _DWORD, int))(a1 + 12))(8 * v16, 0, 859000131);
        if ( v13 )
        {
          HvpGenerateLogMetadata(v18, v13, &v16, v12);
          v14 = v16;
          v19[0] = 1162638920;
          v19[4] = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 40);
          v19[5] = v16;
          v19[1] = 8 * (v16 + 5) + (v11 << 9);
          if ( HvpIsMetadataArrayCoherent(v19, v13, v16) )
          {
            v9 = HvpRecoverDataReadRoutine(a1, a3, (v8 + 1027) & 0xFFFFFE00, v11 << 9, (unsigned int *)&v17);
            if ( v9 >= 0 )
            {
              v9 = HvpApplyLogEntry(a1, v19, v13, v17);
              if ( v9 >= 0 )
              {
                if ( a4 )
                  HvpUpdateRecoveryVector(v13, v14, a4);
                v9 = 1073741833;
              }
            }
          }
          else
          {
            v9 = -1073741492;
          }
          (*(void (__fastcall **)(unsigned int *, unsigned int))(a1 + 16))(v13, 8 * v14);
        }
        else
        {
          v9 = -1073741801;
        }
      }
      else
      {
        v9 = 0;
      }
    }
    else if ( CmpSelfHeal || (CmpBootType & 6) != 0 )
    {
      v9 = 1073741833;
      *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4088) |= 4u;
    }
    else
    {
      v9 = -1073741492;
    }
  }
  return v9;
}
