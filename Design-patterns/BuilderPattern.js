class Address {
    constructor(zip, street) {
        this.zip = zip;
        this.street = street;
    }
}


class User {
    constructor(name) {
        this.name = name;
    }
}

class newWayUser {
    constructor(name, { age, address, phone } = {}) {
        this.name = name;
        this.age = age;
        this.Address = address;
        this.phone = phone;
    }
}


class userBuilder {
    constructor(name) {
        this.user = new User(name);
    }

    setAge(age) {
        this.user.age = age;
        return this;
    }

    setPhone(phone) {
        this.user.phone = phone;
        return this;
    }
    setAddress(address) {
        this.user.address = address;
        return this;
    }

    build() {
        return this.user;
    }
}


// let user = new userBuilder("tarun").setAge(30)

// console.log(user);




