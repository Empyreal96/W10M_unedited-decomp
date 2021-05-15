// WheapWmiExecutePolicyManagementMethod 
 
int __fastcall WheapWmiExecutePolicyManagementMethod(int a1, unsigned int a2, int *a3, unsigned int a4, int *a5)
{
  int v6; // r5
  int result; // r0
  int v8; // r3
  __int64 v9; // r0
  int v10; // [sp+0h] [bp-10h] BYREF
  int v11[3]; // [sp+4h] [bp-Ch] BYREF

  v6 = 0;
  v10 = 0;
  v11[0] = 0;
  switch ( a1 )
  {
    case 1:
      v9 = WheapGetAllPolicyBufferSize();
      v6 = v9 + 12;
      if ( HIDWORD(v9) < (unsigned int)(v9 + 12) )
        goto LABEL_18;
      *a3 = 0;
      a3[2] = v9;
      result = WheapGetAllPolicyValues(v11, v9, a3 + 3);
      v8 = v11[0];
      goto LABEL_20;
    case 2:
      if ( a4 < 4 )
        goto LABEL_13;
      v6 = 8;
      if ( a2 < 8 )
        goto LABEL_18;
      result = WheapGetPolicyValue(*a3, &v10);
      *a3 = result;
      if ( result )
        goto LABEL_21;
      v8 = v10;
LABEL_20:
      a3[1] = v8;
      goto LABEL_21;
    case 3:
      if ( a4 >= 8 )
      {
        v6 = 4;
        v10 = a3[1];
        if ( a2 >= 4 )
        {
          result = WheapSetPolicyValue(*a3, &v10);
          goto LABEL_11;
        }
LABEL_18:
        result = -1073741789;
        goto LABEL_21;
      }
LABEL_13:
      result = -1073741811;
      goto LABEL_21;
    case 4:
      v6 = 4;
      if ( a2 >= 4 )
      {
        result = WheapCommitPolicy();
LABEL_11:
        *a3 = result;
        goto LABEL_21;
      }
      goto LABEL_18;
  }
  result = -1073741161;
LABEL_21:
  *a5 = v6;
  return result;
}
