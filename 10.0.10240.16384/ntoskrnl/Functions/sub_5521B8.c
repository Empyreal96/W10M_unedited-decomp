// sub_5521B8 
 
void __fastcall sub_5521B8(int a1)
{
  int v1; // r5
  int *v2; // r4
  int v3; // r6

  v2 = &KdDebuggerDataBlock;
  v3 = 216;
  do
  {
    *(int *)((char *)v2 + a1 - (_DWORD)&KdDebuggerDataBlock) = KiWaitAlways ^ bswap32(__ROR4__(
                                                                                        KiWaitNever ^ *v2,
                                                                                        -(char)KiWaitNever) ^ v1);
    ++v2;
    --v3;
  }
  while ( v3 );
  JUMPOUT(0x4F0D88);
}
