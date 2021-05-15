// RtlCompareMemory 
 
int __fastcall RtlCompareMemory(unsigned __int8 *a1, int a2, int a3)
{
  int v3; // r5
  int v4; // r4
  int v5; // r1
  int v6; // t1

  v3 = a3;
  if ( !a3 )
    return 0;
  v4 = a2 - (_DWORD)a1;
  do
  {
    v5 = a1[v4];
    v6 = *a1++;
    if ( v6 != v5 )
      break;
    --a3;
  }
  while ( a3 );
  return v3 - a3;
}
