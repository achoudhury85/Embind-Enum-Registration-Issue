
// This should succeed
var enum2 = Module.GetEnum2(2);
console.log("Enum2: " + enum2.value);

// This should also succeed but fails instead
var enum1 = Module.GetEnum1(3);
console.log("Enum1: " + enum1.value);
