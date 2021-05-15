// _SysCtxOpenMachine 
 
int __fastcall SysCtxOpenMachine(int a1, int a2, int a3, int a4, int a5, int a6, _DWORD *a7)
{
  _BYTE *v8; // r0
  _BYTE *v9; // r6
  int v11; // r0
  int v12; // [sp+8h] [bp-28h] BYREF
  int v13; // [sp+Ch] [bp-24h]
  int v14; // [sp+10h] [bp-20h]
  int v15; // [sp+14h] [bp-1Ch] BYREF
  int v16; // [sp+18h] [bp-18h]

  *a7 = 0;
  v15 = 0;
  v16 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v8 = (_BYTE *)ExAllocatePoolWithTag(1, 28, 1380994640);
  v9 = v8;
  if ( !v8 )
    return sub_818EBC();
  memset(v8, 0, 28);
  *(_DWORD *)v9 = 167772160;
  if ( RegRtlOpenKeyTransacted(-2147483646, L"SYSTEM", 0, 0x2000000, (int)&v15, v14) || v15 && SysCtxOpenControlSet() )
    goto LABEL_12;
  if ( a4 )
  {
    if ( a4 == -1 )
      goto LABEL_9;
    v11 = a4;
  }
  else
  {
    v11 = -2147483645;
  }
  if ( RegRtlOpenKeyTransacted(v11, 0, 0, 0x2000000, (int)&v12, v14) )
LABEL_12:
    JUMPOUT(0x818EBE);
LABEL_9:
  v9[8] = 1;
  *((_DWORD *)v9 + 1) = v14;
  *((_DWORD *)v9 + 3) = v15;
  *((_DWORD *)v9 + 4) = v16;
  *((_DWORD *)v9 + 6) = v13;
  *((_DWORD *)v9 + 5) = v12;
  *a7 = v9;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  return 0;
}
