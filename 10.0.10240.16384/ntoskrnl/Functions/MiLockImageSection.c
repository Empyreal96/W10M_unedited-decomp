// MiLockImageSection 
 
int __fastcall MiLockImageSection(int result, unsigned __int64 *a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // r6
  unsigned int v6; // lr
  unsigned int v7; // r7
  unsigned int v8; // r2
  __int16 v9; // r3
  unsigned int i; // [sp+8h] [bp-30h] BYREF
  unsigned int v11; // [sp+Ch] [bp-2Ch]
  unsigned int v12; // [sp+10h] [bp-28h]
  int v13; // [sp+14h] [bp-24h]

  v11 = a4;
  v12 = a3;
  v13 = result;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
LABEL_2:
  v6 = *(_DWORD *)a2;
  for ( i = *(_DWORD *)a2; ; i = v7 )
  {
    if ( v6 == 1 )
    {
      result = ExBlockOnAddressPushLock((int)&dword_632F60, a2, &i, 4, 0);
      goto LABEL_2;
    }
    do
      v7 = __ldrex((unsigned int *)a2);
    while ( v7 == v6 && __strex(v6 + 1, (unsigned int *)a2) );
    __dmb(0xBu);
    if ( v7 == v6 )
      break;
    v6 = v7;
  }
  if ( v7 < 2 )
  {
    result = MiLockCode(v13, v12, v11, 1);
    do
      v8 = __ldrex((unsigned int *)a2);
    while ( __strex(v8 + 1, (unsigned int *)a2) );
    __dmb(0xBu);
    __dmb(0xFu);
    if ( dword_632F60 )
      result = ExfUnblockPushLock((int)&dword_632F60, 0);
  }
  v9 = *(_WORD *)(v5 + 308) + 1;
  *(_WORD *)(v5 + 308) = v9;
  if ( !v9 && *(_DWORD *)(v5 + 100) != v5 + 100 )
    result = sub_7F26DC(result);
  return result;
}
