// RtlQueryImageFileExecutionOptions 
 
int __fastcall RtlQueryImageFileExecutionOptions(int a1, unsigned __int16 *a2, int a3, int *a4)
{
  int result; // r0
  int v7[4]; // [sp+8h] [bp-10h] BYREF

  v7[0] = a3;
  v7[1] = (int)a4;
  result = RtlpOpenBaseImageFileOptionsKey(v7);
  if ( result >= 0 )
    result = RtlQueryImageFileKeyOption(v7[0], a2, 4, a4, 4u, 0);
  return result;
}
