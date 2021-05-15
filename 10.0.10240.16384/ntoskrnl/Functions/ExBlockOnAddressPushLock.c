// ExBlockOnAddressPushLock 
 
int __fastcall ExBlockOnAddressPushLock(int a1, unsigned __int64 *a2, unsigned int *a3, int a4, int a5)
{
  int v9; // r0
  unsigned int v11; // r4
  unsigned int v12; // r3
  unsigned __int64 v13; // kr00_8
  bool v14; // zf
  int v15; // r3
  _DWORD v16[24]; // [sp-40h] [bp-60h] BYREF

  v16[16] = a4;
  v9 = ExBlockPushLock(a1, v16);
  switch ( a4 )
  {
    case 4:
      v14 = *(_DWORD *)a2 == *a3;
      break;
    case 1:
      v14 = *(unsigned __int8 *)a2 == *(unsigned __int8 *)a3;
      break;
    case 2:
      return sub_529154(v9);
    case 8:
      v11 = *a3;
      v12 = a3[1];
      do
        v13 = __ldrexd(a2);
      while ( v13 == __PAIR64__(v12, v11) && __strexd(__PAIR64__(v12, v11), a2) );
      if ( (_DWORD)v13 != *a3 )
        goto LABEL_19;
      v14 = HIDWORD(v13) == a3[1];
      break;
    default:
      goto LABEL_20;
  }
  if ( v14 )
  {
    v15 = 1;
    goto LABEL_15;
  }
LABEL_19:
  v15 = 0;
LABEL_15:
  if ( !v15 )
  {
LABEL_20:
    ExpUnblockPushLock(a1, v16, 0);
    return 0;
  }
  return ExTimedWaitForUnblockPushLock(a1, v16, a5);
}
