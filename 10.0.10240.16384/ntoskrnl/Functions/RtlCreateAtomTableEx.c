// RtlCreateAtomTableEx 
 
int __fastcall RtlCreateAtomTableEx(unsigned int a1, int a2, _DWORD *a3, int a4)
{
  int v4; // r4
  int v7; // r6
  int v8; // r7
  _BYTE *v9; // r0
  _DWORD *v10; // r5
  int v12[8]; // [sp+0h] [bp-20h] BYREF

  v12[0] = (int)a3;
  v12[1] = a4;
  v4 = 0;
  v7 = a1;
  if ( !*a3 )
  {
    if ( a1 <= 1 )
      v7 = 37;
    v4 = RtlULongLongToULong(28 * (v7 - 1), (28 * (unsigned __int64)(unsigned int)(v7 - 1)) >> 32, v12);
    if ( v4 >= 0 )
    {
      v8 = v12[0] + 28;
      if ( (unsigned int)(v12[0] + 28) < v12[0] )
      {
        v4 = -1073741675;
      }
      else
      {
        v4 = 0;
        v9 = (_BYTE *)RtlpAllocateAtom(v12[0] + 28, 1416459329);
        v10 = v9;
        if ( v9 )
        {
          memset(v9, 0, v8);
          v10[5] = v7;
          if ( !RtlpInitializeHandleTableForAtomTable(v10) )
            return sub_554EB4(v10);
          RtlpInitializeLockAtomTable(v10);
          v10[4] = a2;
          *v10 = 1836020801;
          v10[1] = 1;
          *a3 = v10;
        }
        else
        {
          v4 = -1073741801;
        }
      }
    }
  }
  return v4;
}
