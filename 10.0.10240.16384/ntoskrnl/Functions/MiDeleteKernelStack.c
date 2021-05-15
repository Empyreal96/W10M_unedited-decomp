// MiDeleteKernelStack 
 
int __fastcall MiDeleteKernelStack(int a1, char a2)
{
  int v4; // r5
  unsigned int v5; // r0
  int v6; // r4
  unsigned int v7; // r0
  int v8; // [sp+0h] [bp-20h] BYREF
  int v9; // [sp+4h] [bp-1Ch]
  int v10; // [sp+8h] [bp-18h]
  int v11; // [sp+Ch] [bp-14h]

  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  if ( (a2 & 2) != 0 )
    return sub_5483C4();
  if ( (a2 & 1) != 0 )
    v4 = 15;
  else
    v4 = (unsigned __int8)byte_634840;
  MiDeleteKernelStackPages(a1 - 4 * v4, v4 + 1, &v8);
  do
    v5 = __ldrex(&dword_634DA8);
  while ( __strex(v5 - v4, &dword_634DA8) );
  v6 = v8;
  MiReturnResidentAvailable(v8);
  do
    v7 = __ldrex(&dword_634A04[1]);
  while ( __strex(v7 + v6, &dword_634A04[1]) );
  MiReleasePtes(&dword_634D58, a1 - 4 * v4, v4 + 1);
  MiReturnCommit((int)MiSystemPartition, v4 - v9);
  return v8;
}
