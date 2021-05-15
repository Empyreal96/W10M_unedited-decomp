// sub_7E8E6C 
 
void sub_7E8E6C()
{
  int v0; // r1
  int v1; // r0
  int v2; // t1
  int v3; // r3
  int v4; // r3
  unsigned int v5; // r0
  char v6; // r6
  int v7; // r7
  int *v8; // r8
  _DWORD *v9; // r9
  _DWORD *v10; // r0
  _DWORD *v11; // r4
  int v12; // r3
  int v13; // r5
  int v14; // r0

  if ( (v6 & 2) != 0 )
    v6 |= 1u;
  v10 = (_DWORD *)ExAllocatePoolWithQuotaTag(0x208u, 12 * (v7 - 1) + 1060, 1649439826);
  v11 = v10;
  if ( !v10 )
LABEL_39:
    JUMPOUT(0x6FFE2C);
  *v10 = 0;
  v10[1] = 0;
  v10[4] = 0;
  if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0) & 8) != 0 )
  {
    if ( (v6 & 1) != 0 )
    {
      if ( RtlpOpenThreadToken() >= 0 )
      {
        v11[4] |= 1u;
        ZwSetInformationThread();
        goto LABEL_19;
      }
LABEL_37:
      ExFreePoolWithTag((unsigned int)v11);
      goto LABEL_39;
    }
    if ( RtlpOpenThreadToken() < 0 )
      goto LABEL_37;
  }
LABEL_19:
  if ( *v11 )
    goto LABEL_24;
  if ( (v6 & 2) != 0 )
  {
    if ( ZwOpenProcessTokenEx() >= 0 )
    {
      v12 = v11[4] | 2;
LABEL_23:
      v11[4] = v12;
LABEL_24:
      v11[2] = v11 + 5;
      v11[3] = v11 + 261;
      v11[261] = v7;
      if ( v7 )
      {
        v0 = 0;
        v1 = v7;
        do
        {
          v2 = *v8++;
          v3 = v11[3] + v0;
          *(_DWORD *)(v3 + 4) = v2;
          *(_DWORD *)(v3 + 8) = 0;
          v4 = v11[3] + v0;
          v0 += 12;
          *(_DWORD *)(v4 + 12) = 2;
          --v1;
        }
        while ( v1 );
      }
      v13 = ZwAdjustPrivilegesToken();
      if ( v13 == -1073741789 )
      {
        while ( 1 )
        {
          v14 = ExAllocatePoolWithQuotaTag(0x208u, 0x400u, 1649439826);
          v11[2] = v14;
          if ( !v14 )
            break;
          v13 = ZwAdjustPrivilegesToken();
          if ( v13 != -1073741789 )
            goto LABEL_28;
          ExFreePoolWithTag(v11[2]);
        }
        v13 = -1073741801;
      }
LABEL_28:
      if ( v13 == 262 )
      {
        if ( v7 == 1 )
        {
LABEL_32:
          v5 = v11[2];
          if ( (_DWORD *)v5 != v11 + 5 && v5 )
            ExFreePoolWithTag(v5);
          ZwClose();
          goto LABEL_34;
        }
        v13 = 0;
      }
      if ( v13 >= 0 )
      {
        *v9 = v11;
        goto LABEL_39;
      }
      goto LABEL_32;
    }
  }
  else if ( RtlImpersonateSelfEx(3, 40, v11) >= 0 )
  {
    v12 = v11[4] | 1;
    goto LABEL_23;
  }
LABEL_34:
  if ( (v11[4] & 1) != 0 )
  {
    ZwSetInformationThread();
    if ( v11[1] )
      ZwClose();
  }
  goto LABEL_37;
}
