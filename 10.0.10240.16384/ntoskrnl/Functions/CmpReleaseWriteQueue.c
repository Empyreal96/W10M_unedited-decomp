// CmpReleaseWriteQueue 
 
int __fastcall CmpReleaseWriteQueue(int a1, _DWORD *a2)
{
  int v2; // r5
  int result; // r0

  v2 = a2[1];
  *a2 = 0;
  a2[1] = 0;
  if ( a2[2] )
    result = sub_7D3CD8();
  else
    result = v2;
  return result;
}
