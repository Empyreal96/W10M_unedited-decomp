// DbgkCreateMinimalProcess 
 
int __fastcall DbgkCreateMinimalProcess(int result)
{
  int v1; // r6
  unsigned int *v2; // r5
  unsigned int v3; // r4
  int v4[8]; // [sp+0h] [bp-B8h] BYREF
  char v5[28]; // [sp+20h] [bp-98h] BYREF

  v1 = result;
  __dmb(0xBu);
  v2 = (unsigned int *)(result + 192);
  do
    v3 = __ldrex(v2);
  while ( __strex(v3 | 0x400001, v2) );
  __dmb(0xBu);
  if ( *(_DWORD *)(result + 340) )
  {
    memset(v5, 0, sizeof(v5));
    v4[0] = 3932196;
    v4[1] = 8;
    v4[6] = 2;
    result = DbgkpSendApiMessage(v1, 0, (int)v4);
  }
  return result;
}
