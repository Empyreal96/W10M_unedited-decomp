// CcCopyWriteWontFlush 
 
int __fastcall CcCopyWriteWontFlush(int a1, int a2, unsigned int a3)
{
  _DWORD *v5; // r0
  int v6; // r1
  int result; // r0

  if ( a3 >= 0x1000000 || (*(_DWORD *)(a1 + 44) & 0x10) != 0 )
    goto LABEL_12;
  v5 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v6 = (v5[240] >> 9) & 7;
  if ( (*(_DWORD *)(v5[84] + 192) & 0x100000) != 0 )
    return sub_53D444();
  if ( ((v5[240] >> 9) & 7u) < 2 && v5 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v5[250] )
    v6 = 2;
  if ( v6 <= 0 || IoIsFileOriginRemote(a1) && !CcCanIWriteStream(a1, a3, 0, 0) )
LABEL_12:
    result = 0;
  else
    result = 1;
  return result;
}
