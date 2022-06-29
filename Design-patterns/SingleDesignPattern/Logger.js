class Logger {
    constructor() {
        if (Logger.instance == null) {
            this.logs = [];
            Logger.instance = this;
        }
        return Logger.instance;
    }

    log(message) {
        // console.log(this.logs);
        this.logs.push(message);
    }

    printLogCount() {
        console.log(`${this.logs.length} logs counts`);
    }
}

const logger = new Logger();
Object.freeze(logger);

module.exports = logger;