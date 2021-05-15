// KeGetBugMessageResourceEntry 
 
int __fastcall KeGetBugMessageResourceEntry(unsigned int a1, int a2, int a3, int a4)
{
  int result; // r0
  int v5[2]; // [sp+0h] [bp-8h] BYREF

  v5[0] = a3;
  v5[1] = a4;
  if ( RtlFindMessageInTable((int *)KiBugCodeMessages, a1, v5) >= 0 )
    result = v5[0];
  else
    result = 0;
  return result;
}
