// RtlpOpenBaseImageFileOptionsKey 
 
int __fastcall RtlpOpenBaseImageFileOptionsKey(int *a1)
{
  int v2; // r3
  int result; // r0
  unsigned int v4; // r1
  unsigned int v5; // [sp+0h] [bp-28h]

  v2 = dword_641DC4;
  v5 = dword_641DC4;
  if ( dword_641DC4 )
  {
LABEL_2:
    *a1 = v2;
    return 0;
  }
  __mrc(15, 0, 13, 0, 3);
  result = ZwOpenKey();
  if ( result >= 0 )
  {
    __dmb(0xBu);
    do
      v4 = __ldrex((unsigned int *)&dword_641DC4);
    while ( !v4 && __strex(v5, (unsigned int *)&dword_641DC4) );
    __dmb(0xBu);
    if ( v4 )
      return sub_7E87C8();
    v2 = v5;
    goto LABEL_2;
  }
  return result;
}
