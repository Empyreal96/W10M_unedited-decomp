// StRtlIoStorInfoSetNvCachePriority 
 
int __fastcall StRtlIoStorInfoSetNvCachePriority(int a1, unsigned int a2, int a3, int a4)
{
  char v4; // r5
  int result; // r0
  char v7; // [sp+0h] [bp-10h] BYREF
  __int16 v8; // [sp+1h] [bp-Fh]
  char v9; // [sp+3h] [bp-Dh]
  int v10; // [sp+4h] [bp-Ch]

  v10 = a4;
  v4 = a2;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  if ( a2 > 0xF )
    return -1073741811;
  result = IoGetGenericIrpExtension(a1, (int)&v7, 4u);
  if ( result >= 0 || result == -1073741275 )
  {
    v7 = v4 & 0xF | v7 & 0xE0 | 0x10;
    result = IoSetGenericIrpExtension(a1, (int)&v7, 4u, 1);
  }
  return result;
}
