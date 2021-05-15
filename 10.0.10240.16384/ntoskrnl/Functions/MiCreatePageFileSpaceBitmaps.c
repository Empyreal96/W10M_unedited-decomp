// MiCreatePageFileSpaceBitmaps 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiCreatePageFileSpaceBitmaps(unsigned int a1)
{
  int v2; // r5
  int result; // r0
  int v4; // r3
  int v5; // r3

  v2 = 4 * (((a1 & 0x1F) != 0) + (a1 >> 5));
  result = ExAllocatePoolWithTag(512, 2 * (v2 + 10), 1649438029);
  if ( !result )
    return 0;
  v4 = 1;
  *(_QWORD *)result = *(_QWORD *)(&a1 - 1);
  v5 = result + 20;
  *(_QWORD *)(result + 8) = *(_QWORD *)(&a1 - 1);
  *(_DWORD *)(result + 16) = result + 20 + v2;
  return result;
}
