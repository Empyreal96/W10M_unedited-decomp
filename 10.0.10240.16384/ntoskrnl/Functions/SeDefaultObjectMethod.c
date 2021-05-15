// SeDefaultObjectMethod 
 
int __fastcall SeDefaultObjectMethod(int a1, int a2, _DWORD *a3, int a4, int a5, int *a6)
{
  int result; // r0
  int v10; // r4
  int v11; // r3
  int v12; // r2
  int v13; // r6
  int v14[6]; // [sp+8h] [bp-18h] BYREF

  v14[0] = (int)a3;
  v14[1] = a4;
  switch ( a2 )
  {
    case 0:
      return ObSetSecurityDescriptorInfo(a1, a3, a4);
    case 1:
      v13 = ObpReferenceSecurityDescriptor(a1 - 24);
      v14[0] = v13;
      v10 = SeQuerySecurityDescriptorInfo(a3, a4, a5, v14);
      if ( !v13 )
        goto LABEL_8;
      ObDereferenceSecurityDescriptor(v13, 1);
      result = v10;
      break;
    case 2:
      v12 = *a6;
      *a6 = 0;
      ObDereferenceSecurityDescriptor(v12 & 0xFFFFFFF8, (v12 & 7) + 1);
      return 0;
    case 3:
      if ( a4 )
      {
        v10 = ObLogSecurityDescriptor(a4, v14, 8);
        if ( v10 >= 0 )
        {
          ExFreePoolWithTag(a4);
          if ( v14[0] )
            v11 = v14[0] + 7;
          else
            v11 = 0;
          *(_DWORD *)(a1 - 4) = v11;
        }
LABEL_8:
        result = v10;
      }
      else
      {
        result = sub_7FB7D0();
      }
      break;
    default:
      KeBugCheckEx(41, 0, -1073741811, 0, 0);
  }
  return result;
}
